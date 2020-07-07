#ifndef _USER_COMMAND_IMPL_CPP
#define _USER_COMMAND_IMPL_CPP

#include <functional>
#include <algorithm>
#include <iostream>
#include <utility>

#include "states/Tree_Context.h"
#include "User_Command_Factory_Impl.h"
#include "User_Command_Impl.h"

User_Command_Impl::User_Command_Impl (Tree_Context &context)
  : tree_context_ (context) {
}

User_Command_Impl::~User_Command_Impl () = default;

Format_Command::Format_Command (Tree_Context &context, std::string new_format)
  : User_Command_Impl (context),
    format_ (std::move(new_format)) {
}

bool
Format_Command::execute () { 
  tree_context_.format (format_);
  return true;
}


void
Format_Command::print_valid_commands () { 
  std::cout << "\n";
  std::cout << "1. expr [expression]\n";
  std::cout << "2a. eval [post-order]\n";
  std::cout << "2b. print [in-order | pre-order | post-order | level-order]\n";
  std::cout << "0a. format [in-order | post-order]\n";
  std::cout << "0b. set [variable=value]\n";
  std::cout << "0c. quit\n";
  std::cout << "\n";
}


Expr_Command::Expr_Command (Tree_Context &context,
                            std::string new_expr)
  : User_Command_Impl (context),
    expr_ (std::move(new_expr)) {
}

bool
Expr_Command::execute () {
  tree_context_.expr(expr_);
  return true;
}

void
Expr_Command::print_valid_commands () { 
  std::cout << "\n";
  std::cout << "1a. eval [post-order]\n";
  std::cout << "1b. print [in-order | pre-order | post-order | level-order]\n";
  std::cout << "1c. expr [expression]\n";
  std::cout << "0a. format [in-order | post-order]\n";
  std::cout << "0b. set [variable=value]\n";
  std::cout << "0c. quit\n";
  std::cout << "\n";
}

Print_Command::Print_Command (Tree_Context &context,
                              std::string print_format)
  : User_Command_Impl (context),
    format_ (std::move(print_format)) {
}

bool
Print_Command::execute () { 
  tree_context_.print (format_);
  return true;
}

void
Print_Command::print_valid_commands () { 
  std::cout << "\n";
  std::cout << "1a. eval [post-order]\n";
  std::cout << "1b. print [in-order | pre-order | post-order | level-order]\n";
  std::cout << "1c. expr [expression]\n";
  std::cout << "0a. format [in-order | post-order]\n";
  std::cout << "0b. set [variable=value]\n";
  std::cout << "0c. quit\n";
  std::cout << "\n";
}

Eval_Command::Eval_Command (Tree_Context &context,
                            std::string eval_format)
  : User_Command_Impl (context),
    format_ (std::move(eval_format)) {
}

bool
Eval_Command::execute ()
{ 
  tree_context_.evaluate (format_);
  return true;
}

void
Eval_Command::print_valid_commands () { 
  std::cout << "\n";
  std::cout << "1a. eval [post-order]\n";
  std::cout << "1b. print [in-order | pre-order | post-order | level-order]\n";
  std::cout << "1c. expr [expression]\n";
  std::cout << "0a. format [in-order | post-order]\n";
  std::cout << "0b. set [variable=value]\n";
  std::cout << "0c. quit\n";
  std::cout << "\n";
}

Set_Command::Set_Command (Tree_Context &context,
                          std::string key_value_pair)
  : User_Command_Impl (context),
    key_value_pair_ (std::move(key_value_pair)) {
}

bool
Set_Command::execute () { 
  tree_context_.set (key_value_pair_);
  return true;
}

void
Set_Command::print_valid_commands () { 
  std::cout << "\n";

  // if we've never had a format command called successfully, then we
  // have a different set of valid commands

  char abc [3] = { 'a','b','c' };
  int step = 1;
  int sub_step = 0;
  std::string formatMessage (". format [in-order | post-order]");

  if (!tree_context_.formatted())
    std::cout << step++ << formatMessage << "\n";

  std::cout << step++ << ". expr [expression]\n";
  std::cout << step << "a. eval [post-order]\n";
  std::cout << step++ << "b. print [in-order | pre-order | post-order | level-order]\n";

  step = 0;

  if (tree_context_.formatted())
    std::cout << step << abc[sub_step++] << formatMessage << "\n";

  std::cout << step << abc[sub_step++] << ". set [variable=value]\n";
  std::cout << step << abc[sub_step++] << ". quit\n";
  std::cout << "\n";
}

Quit_Command::Quit_Command (Tree_Context &context)
  : User_Command_Impl (context) {
}

bool
Quit_Command::execute () { 
  return false; 
}

void
Quit_Command::print_valid_commands () { 
}

Macro_Command::Macro_Command (Tree_Context &context,
                              std::vector <User_Command> macro_commands)
  : User_Command_Impl (context),
    macro_commands_ (std::move(macro_commands)) {
}

bool
Macro_Command::execute () {
    for (auto &command : macro_commands_)
        command.execute();

#if 0
  std::for_each (macro_commands_.begin (),
                 macro_commands_.end (),
                 std::mem_fun_ref (&User_Command::execute));

  std::for_each (macro_commands_.begin (),
                 macro_commands_.end (),
                 [] (User_Command &c)
                 { 
                   c.execute();
                 });
#endif
  return true;
}

void
Macro_Command::print_valid_commands () { 
}

Null_Command::Null_Command (Tree_Context &context)
  : User_Command_Impl (context) {
}

bool 
Null_Command::execute () { 
  return true; 
}

void 
Null_Command::print_valid_commands () {
  std::cout << "\n1a. format [in-order | post-order]\n";
  std::cout << "1b. set [variable=value]\n";
  std::cout << "2. expr [expression]\n";
  std::cout << "3a. eval [post-order]\n";
  std::cout << "3b. print [in-order | pre-order | post-order | level-order]\n";
  std::cout << "0. quit\n\n";
}

#endif /* _USER_COMMAND_IMPL_CPP */
