/* -*- C++ -*- */
#ifndef _EXPRESSION_TREE_COMMAND_CPP
#define _EXPRESSION_TREE_COMMAND_CPP

#include "Expression_Tree_Command.h"
#include "Expression_Tree_Command_Impl.h"

Expression_Tree_Command::Expression_Tree_Command (Expression_Tree_Command_Impl *impl)
  : command_impl_ (impl)
{
}

Expression_Tree_Command::Expression_Tree_Command (const Expression_Tree_Command &rhs)
  : command_impl_ (rhs.command_impl_)
{
}

Expression_Tree_Command & 
Expression_Tree_Command::operator= (const Expression_Tree_Command &rhs)
{
  // check for self assignment first
  if (this != &rhs)
    /// we just make use of the Refcounter functionality here
    command_impl_ = rhs.command_impl_;
  return *this;
}

Expression_Tree_Command::~Expression_Tree_Command (void)
{
}

bool
Expression_Tree_Command::execute (void)
{
  return command_impl_->execute ();
}

void
Expression_Tree_Command::print_valid_commands (void)
{
  command_impl_->print_valid_commands ();
}

#endif /* _EXPRESSION_TREE_COMMAND_CPP */
