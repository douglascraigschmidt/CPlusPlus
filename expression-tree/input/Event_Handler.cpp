#ifndef __EVENT_HANDLER_CPP
#define __EVENT_HANDLER_CPP

#include <iostream>

#include "Event_Handler.h"
#include "Reactor.h"
#include "commands/User_Command_Impl.h"
#include "states/State.h"

std::unique_ptr<Event_Handler>
Event_Handler::make_handler (bool verbose) {
  if (verbose)
    return std::make_unique<Verbose_Mode_Event_Handler>();
  else
    return std::make_unique<Succinct_Mode_Event_Handler>();
}

void 
Event_Handler::handle_input () {
  prompt_user ();

  std::string input;
  
  if (!get_input(input)) {
    Reactor::instance ()->end_event_loop ();
    return;
  }

  User_Command command = make_command (input);
  
  try {
    if (!execute_command(command)) 
      Reactor::instance ()->end_event_loop ();
    else {
      last_valid_command_ = command;
      command.print_valid_commands ();
    }
  } catch (Expression_Tree::Invalid_Iterator &e) {
    std::cout << "\nERROR: Bad traversal type (" << e.what() << ")\n";
    last_valid_command_.print_valid_commands ();
  } catch (State::Invalid_State &e) {
    std::cout << "\nERROR: Can't call that command yet.\n";
    last_valid_command_.print_valid_commands ();
  }
}

bool
Event_Handler::get_input (std::string &input) {
  std::getline (std::cin, input);
  return !std::cin.eof();
}

bool
Event_Handler::execute_command (User_Command &command) {
  return command.execute ();
}

Event_Handler::Event_Handler ()
  : tree_context_ (),
    command_factory_ (tree_context_),
    last_valid_command_ (new Null_Command (tree_context_)) {
}

Event_Handler::~Event_Handler () = default;

Verbose_Mode_Event_Handler::Verbose_Mode_Event_Handler (void)
  : prompted_ (false) {
}

Verbose_Mode_Event_Handler::~Verbose_Mode_Event_Handler () = default;

void
Verbose_Mode_Event_Handler::prompt_user () {
  if (!prompted_) {
    std::cout << "1a. format [in-order | post-order]\n";
    std::cout << "1b. set [variable=value]\n";
    std::cout << "2. expr [expression]\n";
    std::cout << "3a. eval [post-order]\n";
    std::cout << "3b. print [in-order | pre-order | post-order | level-order]\n";
    std::cout << "0. quit\n";
    prompted_ = true;
  }
  std::cout << "> ";
  std::cout.flush ();
}

User_Command
Verbose_Mode_Event_Handler::make_command (const std::string &input) {
  return command_factory_.make_command (input);
}

Succinct_Mode_Event_Handler::Succinct_Mode_Event_Handler () = default;

Succinct_Mode_Event_Handler::~Succinct_Mode_Event_Handler () = default;

void
Succinct_Mode_Event_Handler::prompt_user () {
  std::cout << "> ";
  std::cout.flush ();
}

User_Command
Succinct_Mode_Event_Handler::make_command (const std::string &input) {
  return command_factory_.make_macro_command (input);
}

#endif /* _EVENT_HANDLER_CPP */
