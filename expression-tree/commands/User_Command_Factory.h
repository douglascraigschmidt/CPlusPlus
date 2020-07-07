/* -*- C++ -*- */
#ifndef _USER_COMMAND_FACTORY_H
#define _USER_COMMAND_FACTORY_H

#include <string>

#include "commands/User_Command.h"
#include "User_Command_Factory_Impl.h"
#include "utils/Refcounter.h"

// Forward declarations.
class Iterator_Impl;
class Tree_Context;

/**
 * @class User_Command_Factory
 *
 * @brief Interface for the Factory Method pattern used create the
 *        appropriate @a User_Command based on a string supplied by
 *        the caller.
 *
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor" that
 *        creates the designated commands.
 */
class User_Command_Factory
{
public:
  /// Default ctor that stores the designated @ tree_context.
  explicit User_Command_Factory (Tree_Context &tree_context);

  /// Copy ctor - needed for reference counting.
  User_Command_Factory (const User_Command_Factory &f);

  /// Assignment operator - needed for reference counting.
  User_Command_Factory &operator= (const User_Command_Factory &f);

  /// Dtor.
  ~User_Command_Factory ();

  /// Factory method that makes the requested command.  This method is
  /// the primary method used by clients.
  User_Command make_command (const std::string &command);

  /// Factory method that makes the requested macro command.
  User_Command make_macro_command (const std::string &);

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management.
  Refcounter <User_Command_Factory_Impl> factory_impl_;
};

#endif /* _USER_COMMAND_FACTORY_H */
