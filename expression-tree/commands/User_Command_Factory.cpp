#ifndef _ET_COMMAND_FACTORY_CPP
#define _ET_COMMAND_FACTORY_CPP

#include "User_Command_Factory.h"
#include "User_Command_Factory_Impl.h"

// Default constructor.
User_Command_Factory::User_Command_Factory (Tree_Context &tree_context)
  // There is only one tree implementation, so we create it here.
  : factory_impl_ (new User_Command_Factory_Impl (tree_context))
{
}

// Copy ctor - needed for reference counting.
User_Command_Factory::User_Command_Factory (const User_Command_Factory &f)
  // wrap the pointer in a ref count object
  : factory_impl_ (f.factory_impl_)
{
}

/// Assignment operator - needed for reference counting.
User_Command_Factory &
User_Command_Factory::operator= (const User_Command_Factory &f)
{
  // check for self assignment first
  if (this != &f)
    /// we just make use of the Refcounter functionality here
    factory_impl_ = f.factory_impl_;

  return *this;
}

// Destructor.
User_Command_Factory::~User_Command_Factory () = default;

// Method to create the binary tree to traverse.
User_Command
User_Command_Factory::make_command (const std::string &s) {
  return factory_impl_->make_command (s);
}

User_Command
User_Command_Factory::make_macro_command (const std::string &s) {
  return factory_impl_->make_macro_command (s);
}

#endif /* _ET_COMMAND_FACTORY_H */
