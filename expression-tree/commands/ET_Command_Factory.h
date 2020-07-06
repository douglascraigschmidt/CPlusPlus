/* -*- C++ -*- */
#ifndef _ET_COMMAND_FACTORY_H_
#define _ET_COMMAND_FACTORY_H_

#include <string>
#include "commands/ET_User_Command.h"
#include "ET_Command_Factory_Impl.h"
#include "utils/Refcounter.h"

// Forward declarations.
class ET_Iter_Impl;
class Tree_Context;

/**
 * @class User_Command_Factory
 * @brief Interface for the Abstract Factory pattern that is used
 *        create the appropriate @a User_Command based on a
 *        string supplied by the caller.  
 *
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor"
 *        that creates the designated commands.
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

  /// Make the requested command.  This method is the primary method
  /// used by clients.  
  User_Command make_command (const std::string &command);

  /// Make the requested macro command.  This method is used in the
  /// implementation of the various commands.
  User_Command make_macro_command (const std::string &);

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management. 
  Refcounter <User_Command_Factory_Impl> factory_impl_;
};

#endif /* _ET_COMMAND_FACTORY_H_ */
