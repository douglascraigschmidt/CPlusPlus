/* -*- C++ -*- */
#ifndef _USER_COMMAND_FACTORY_IMPL_H
#define _USER_COMMAND_FACTORY_IMPL_H

#include <string>
#include <map>
#include "commands/User_Command.h"
#include "states/Tree_Context.h"
#include "utils/Refcounter.h"

// Forward declarations.
class Traversal_Strategy_Impl;
class Iterator_Impl;
class User_Command_Impl;

/**
 * @class User_Command_Factory_Impl
 *
 * @brief Implementation of the Factory Method pattern that to create
 *        various types of @a Expression_Tree_Commands.
 * 
 *        Plays the role of the "implementor" base class in the Bridge
 *        pattern.
 */
class User_Command_Factory_Impl {
  /// Needed for reference counting.
  friend class Expression_Tree_Command_Factory;

public:
  /// Constructor initializes the data member.
  explicit User_Command_Factory_Impl (Tree_Context &);

  /// Dtor - make it virtual since we subclass from this interface.
  virtual ~User_Command_Factory_Impl ();

  /// Factory method that makes the requested command.  This method is
  /// the primary method used by clients.
  virtual User_Command make_command (const std::string &s);

  /// Make the requested macro command.  This method is used in the
  /// implementation of the various commands.
  virtual User_Command make_macro_command (const std::string &);

  /// Factory method that make the requested format command.
  virtual User_Command make_format_command (const std::string &);

  /// Make the requested expression command.  This method is used in
  /// the implementation of the various commands.
  virtual User_Command make_expr_command (const std::string &);

  /// Make the requested print command.  This method is used in the
  /// implementation of the various commands.
  virtual User_Command make_print_command (const std::string &);

  /// Make the requested eval command.  This method is used in the
  /// implementation of the various commands.
  virtual User_Command make_eval_command (const std::string &);

  /// Make the requested format command.  This method is used in the
  /// implementation of the various commands.
  virtual User_Command make_set_command (const std::string &);

  /// Make the requested quit command.  This method is used in the
  /// implementation of the various commands.
  virtual User_Command make_quit_command (const std::string &);

private:
  /// Useful typedefs to simplify use of the STL @a std::map.
  typedef User_Command (User_Command_Factory_Impl::*FACTORY_PTMF)(const std::string &);

  // Maps string-based command names to the corresponding
  // pointer-to-member-function.
  typedef std::map<std::string, FACTORY_PTMF> COMMAND_MAP;

  /// Map used to validate user command input and dispatch
  /// corresponding factory method.
  COMMAND_MAP command_map_;

  /// Holds the expression tree that is the target of the commands.
  Tree_Context &tree_context_;
};

#endif /* _USER_COMMAND_FACTORY_IMPL_H */
