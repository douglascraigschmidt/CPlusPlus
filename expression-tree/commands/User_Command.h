/* -*- C++ -*- */
#ifndef _USER_COMMAND_H
#define _USER_COMMAND_H

#include "utils/Refcounter.h"
#include "User_Command_Impl.h"

/**
 * @class User_Command
 *
 * @brief Interface for the Command pattern to define a command that
 *        performs an operation on the expression tree when executed.
 * 
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor" class
 *        that performs the command.
 */
class User_Command
{
public:
  /// Constructor that assumes ownership of an @a User_Command_Impl *.
  explicit User_Command (User_Command_Impl * = 0);

  /// Copy ctor.
  User_Command (const User_Command &);

  /// Assignment operator.
  User_Command &operator= (const User_Command &);

  /// Dtor.
  ~User_Command ();

  /// Runs the command.
  bool execute ();

  /// Print the valid commands available to users in this state.
  void print_valid_commands ();

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management.
  Refcounter <User_Command_Impl> command_impl_;
};

#endif /* _USER_COMMAND_H */
