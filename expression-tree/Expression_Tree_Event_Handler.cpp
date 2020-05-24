#ifndef _EXPRESSION_TREE_EVENT_HANDLER_CPP
#define _EXPRESSION_TREE_EVENT_HANDLER_CPP

#include <iostream>

#include "Expression_Tree_Event_Handler.h"
#include "Reactor.h"
#include "Expression_Tree_Command_Impl.h"
#include "Expression_Tree_State.h"

Expression_Tree_Event_Handler *
Expression_Tree_Event_Handler::make_handler (bool verbose)
{
  if (verbose)
    return new Verbose_Expression_Tree_Event_Handler;
  else
    return new Macro_Command_Expression_Tree_Event_Handler;
}

void 
Expression_Tree_Event_Handler::handle_input (void)
{
  prompt_user ();

  std::string input;
  
  if (get_input (input) == false)
    Reactor::instance ()->end_event_loop ();
    
  Expression_Tree_Command command = make_command (input);
  
  try
    {
      if (execute_command (command) == false)
        Reactor::instance ()->end_event_loop ();
      else
        {
          last_valid_command_ = command;
          command.print_valid_commands ();
        }
    }
  catch (Expression_Tree::Invalid_Iterator e)
    {
      std::cout << "\nERROR: Bad traversal type (" << e.what() << ")\n";
      last_valid_command_.print_valid_commands ();
    }
  catch (Expression_Tree_State::Invalid_State e)
    {
      std::cout << "\nERROR: Can't call that command yet.\n";
      last_valid_command_.print_valid_commands ();
    }
}

bool
Expression_Tree_Event_Handler::get_input (std::string &input)
{
  return std::getline (std::cin, input) != 0;
}

bool
Expression_Tree_Event_Handler::execute_command (Expression_Tree_Command &command)
{
  return command.execute ();
}

Expression_Tree_Event_Handler::Expression_Tree_Event_Handler (void)
  : tree_context_ (),
    command_factory_ (tree_context_),
    last_valid_command_ (new Null_Command (tree_context_))
{
}

Expression_Tree_Event_Handler::~Expression_Tree_Event_Handler (void)
{
}

Verbose_Expression_Tree_Event_Handler::Verbose_Expression_Tree_Event_Handler (void)
  : prompted_ (false)
{
}

Verbose_Expression_Tree_Event_Handler::~Verbose_Expression_Tree_Event_Handler (void)
{
}

void
Verbose_Expression_Tree_Event_Handler::prompt_user (void)
{
  if (!prompted_)
    {
      std::cout << "1a. format [in-order]\n";
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

Expression_Tree_Command 
Verbose_Expression_Tree_Event_Handler::make_command (const std::string &input)
{
  return command_factory_.make_command (input);
}

Macro_Command_Expression_Tree_Event_Handler::Macro_Command_Expression_Tree_Event_Handler (void)
{
}

Macro_Command_Expression_Tree_Event_Handler::~Macro_Command_Expression_Tree_Event_Handler (void)
{
}

void
Macro_Command_Expression_Tree_Event_Handler::prompt_user (void)
{
  std::cout << "> ";
  std::cout.flush ();
}

Expression_Tree_Command 
Macro_Command_Expression_Tree_Event_Handler::make_command (const std::string &input)
{
  return command_factory_.make_macro_command (input);
}

#endif /* _EXPRESSION_TREE_EVENT_HANDLER_CPP */
