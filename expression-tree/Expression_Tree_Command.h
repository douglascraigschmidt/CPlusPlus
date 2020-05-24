/* -*- C++ -*- */
#ifndef _EXPRESSION_TREE_COMMAND_H_
#define _EXPRESSION_TREE_COMMAND_H_

#include "Refcounter.h"
#include "Expression_Tree_Command_Impl.h"

/**
 * @class Expression_Tree_Command
 * @brief Interface for the Command pattern to define a command that
 *        performs an operation on the expression tree when executed. 
 * 
 *        Plays the role of the "abstraction" class in the Bridge
 *        pattern and delegates to the appropriate "implementor"
 *        class that performs the command.
 */
class Expression_Tree_Command
{
public:
  /// Constructor that assumes ownership of an @a Expression_Tree_Command_Impl *.
  Expression_Tree_Command (Expression_Tree_Command_Impl * = 0);

  /// Copy ctor.
  Expression_Tree_Command (const Expression_Tree_Command &);

  /// Assignment operator.
  Expression_Tree_Command &operator= (const Expression_Tree_Command &);

  /// Dtor.
  ~Expression_Tree_Command (void);

  /// Runs the command.
  bool execute (void);

  /// Print the valid commands available to users.
  void print_valid_commands (void);

private:
  /// Pointer to actual implementation, i.e., the "bridge", which is
  /// reference counted to automate memory management.
  Refcounter <Expression_Tree_Command_Impl> command_impl_;
};

#endif /* _EXPRESSION_TREE_COMMAND_H_ */
