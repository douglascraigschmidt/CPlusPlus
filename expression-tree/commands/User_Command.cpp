/* -*- C++ -*- */
#ifndef _USER_COMMAND_CPP
#define _USER_COMMAND_CPP

#include "commands/User_Command.h"
#include "User_Command_Impl.h"

User_Command::User_Command (User_Command_Impl *impl)
  : command_impl_ (impl)
{
}

User_Command::User_Command (const User_Command &rhs)
= default;

User_Command &
User_Command::operator= (const User_Command &rhs) {
  // Check for self assignment first
  if (this != &rhs)
    /// We just use the Refcounter functionality here.
    command_impl_ = rhs.command_impl_;

  return *this;
}

User_Command::~User_Command ()
= default;

bool
User_Command::execute () {
  return command_impl_->execute ();
}

void
User_Command::print_valid_commands () {
  command_impl_->print_valid_commands ();
}

#endif /* _USER_COMMAND_CPP */
