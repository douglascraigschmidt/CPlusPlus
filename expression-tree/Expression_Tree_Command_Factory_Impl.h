/* -*- C++ -*- */
#ifndef _EXPRESSION_TREE_COMMAND_FACTORY_IMPL_H_
#define _EXPRESSION_TREE_COMMAND_FACTORY_IMPL_H_

#include <string>
#include <map>
#include "Expression_Tree_Command.h"
#include "Expression_Tree_Context.h"
#include "Refcounter.h"

// Forward declarations.
class Traversal_Strategy_Impl;
class Expression_Tree_Iterator_Impl;
class Expression_Tree_Command_Impl;

/**
 * @class Expression_Tree_Command_Factory_Impl
 * @brief Implementation of the Abstract Factory pattern that to
 *        create various types of @a Expression_Tree_Commands.  
 * 
 *        Plays the role of the "implementor" base class in the
 *        Bridge pattern that is used as the basis for the subclasses
 *        that actually create the commands.
 */
class Expression_Tree_Command_Factory_Impl
{
  /// Needed for reference counting.
  friend class Expression_Tree_Command_Factory;

public:
  /// Dtor - make it virtual since we subclass from this interface.
  virtual ~Expression_Tree_Command_Factory_Impl (void) = 0;

  /// Make the requested command.  This method is the primary method
  /// used by clients.  
  virtual Expression_Tree_Command make_command (const std::string &s) = 0;

  /// Make the requested format command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_format_command (const std::string &) = 0;

  /// Make the requested expression command.  This method is used in
  /// the implementation of the various commands.
  virtual Expression_Tree_Command make_expr_command (const std::string &) = 0;

  /// Make the requested print command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_print_command (const std::string &) = 0;

  /// Make the requested eval command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_eval_command (const std::string &) = 0;

  /// Make the requested format command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_set_command (const std::string &) = 0;

  /// Make the requested quit command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_quit_command (const std::string &) = 0;

  /// Make the requested macro command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_macro_command (const std::string &) = 0;

protected:
  /// Ctor - only visible to derived classes.
  Expression_Tree_Command_Factory_Impl (void);
};

/**
 * @class Concrete_Expression_Tree_Command_Factory_Impl
 * @brief This is a concrete factory to create expression tree commands. 
 */
class Concrete_Expression_Tree_Command_Factory_Impl 
  : public Expression_Tree_Command_Factory_Impl
{
public:
  /// Default constructor
  Concrete_Expression_Tree_Command_Factory_Impl (Expression_Tree_Context &);

  /// Dtor
  virtual ~Concrete_Expression_Tree_Command_Factory_Impl (void);

  /// Make the requested command.  This method is the primary method
  /// used by clients.  
  virtual Expression_Tree_Command make_command (const std::string &s);

  /// Make the requested format command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_format_command (const std::string &);

  /// Make the requested expression command.  This method is used in
  /// the implementation of the various commands.
  virtual Expression_Tree_Command make_expr_command (const std::string &);

  /// Make the requested print command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_print_command (const std::string &);

  /// Make the requested eval command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_eval_command (const std::string &);

  /// Make the requested eval command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_set_command (const std::string &);

  /// Make the requested quit command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_quit_command (const std::string &);

  /// Make the requested macro command.  This method is used in the
  /// implementation of the various commands.
  virtual Expression_Tree_Command make_macro_command (const std::string &);

private:
  /// Useful typedefs to simplify use of the STL @std::map.
  typedef Expression_Tree_Command (Concrete_Expression_Tree_Command_Factory_Impl::*FACTORY_PTMF)
    (const std::string &);
  typedef std::map<std::string, FACTORY_PTMF> COMMAND_MAP;

  /// Map used to validate user command input and dispatch
  /// corresponding factory method.
  COMMAND_MAP command_map_;

  /// Holds the expression tree that is the target of the commands.
  Expression_Tree_Context &tree_context_;
};

#endif /* _EXPRESSION_TREE_COMMAND_FACTORY_IMPL_H_ */
