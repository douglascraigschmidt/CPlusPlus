#ifndef _COMMAND_FACTORY_IMPL_CPP
#define _COMMAND_FACTORY_IMPL_CPP

#include <stdexcept>

#include "ET_Command_Factory_Impl.h"

// User_Command_Factory_Impl Constructor.
User_Command_Factory_Impl::User_Command_Factory_Impl ()
= default;

// User_Command_Factory_Impl Destructor.
User_Command_Factory_Impl::~User_Command_Factory_Impl ()
= default;

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_format_command (const std::string &param)
{
  return User_Command (new Format_Command (tree_context_, param));
}

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_expr_command (const std::string &param)
{
  return User_Command (new Expr_Command (tree_context_, param));
}

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_print_command (const std::string &param)
{
  return User_Command (new Print_Command (tree_context_, param));
}

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_eval_command (const std::string &param)
{
  return User_Command (new Eval_Command (tree_context_, param));
}

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_set_command (const std::string &param)
{
  return User_Command (new Set_Command (tree_context_, param));
}

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_quit_command (const std::string &)
{
  return User_Command (new Quit_Command (tree_context_));
}

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_macro_command (const std::string &expr_string)
{
  std::vector <User_Command> macro_commands;

  macro_commands.push_back (this->make_format_command ("in-order"));
  macro_commands.push_back (this->make_expr_command (expr_string));
  macro_commands.push_back (this->make_eval_command ("post-order"));

  return User_Command (new Macro_Command (tree_context_, macro_commands));
}

// Constructor.
Concrete_Expression_Tree_Command_Factory_Impl::Concrete_Expression_Tree_Command_Factory_Impl (Tree_Context &tree_context)
  : command_map_ (),
    tree_context_ (tree_context)
{
  command_map_["format"] = &User_Command_Factory_Impl::make_format_command;
  command_map_["expr"] = &User_Command_Factory_Impl::make_expr_command;
  command_map_["print"] = &User_Command_Factory_Impl::make_print_command;
  command_map_["eval"] = &User_Command_Factory_Impl::make_eval_command;
  command_map_["set"] = &User_Command_Factory_Impl::make_set_command;
  command_map_["quit"] = &User_Command_Factory_Impl::make_quit_command;
}

// Destructor
Concrete_Expression_Tree_Command_Factory_Impl::~Concrete_Expression_Tree_Command_Factory_Impl (void)
= default;

User_Command
Concrete_Expression_Tree_Command_Factory_Impl::make_command (const std::string &input)
{
  // separate the command from the parameters
  std::string::size_type space_pos = input.find (' ');
  std::string parameters = input.substr (space_pos + 1);
  std::string command_keyword = input.substr (0, space_pos);

  // COMMAND_MAP::iterator iter = command_map_.find (command_keyword);
  auto iter = command_map_.find (command_keyword);
  if (iter == command_map_.end ())
    return Concrete_Expression_Tree_Command_Factory_Impl::make_quit_command (parameters);
  else
    {
      auto ptmf = iter->second;
      return (this->*ptmf) (parameters);
    }
}

#endif /* _COMMAND_FACTORY_IMPL_CPP */
