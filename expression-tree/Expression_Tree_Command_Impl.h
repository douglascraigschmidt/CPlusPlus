#ifndef _EXPRESSION_TREE_COMMAND_IMPL_H_
#define _EXPRESSION_TREE_COMMAND_IMPL_H_

#include <string>
#include <vector>
#include <iostream>

// Forward declarations.
class Expression_Tree_Context;
class Expression_Tree_Command;

/**
 * @class Expression_Tree_Command_Impl
 * @brief Implementation of the Command pattern that is used to define a
 *        command performs an operation on the expression tree when
 *        executed. 
 * 
 *        Plays the role of the "implementor" base class in the Bridge
 *        pattern that is used as the basis for the subclasses that
 *        actually define the commands.  
 */
class Expression_Tree_Command_Impl
{
public:

  /// Constructor that provides the appropriate @a Expression_Tree_Context.
  explicit Expression_Tree_Command_Impl (Expression_Tree_Context &);

  /// Destructor.
  virtual ~Expression_Tree_Command_Impl () = 0;

  /// Pure virtual method for executing a command that must be defined
  /// by subclasses.
  virtual bool execute () = 0;

  /// Print the valid commands available to users.
  virtual void print_valid_commands () = 0;

protected:
  /// Reference to the @a Expression_Tree_Context that's the target of
  /// the command. 
  Expression_Tree_Context &tree_context_;
};

/**
 * @class Format_Command
 * @brief Set the desired format, e.g., "in-order," "pre-order,"
 *        "post-order", or "level-order".
 */
class Format_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and the requested format.
  Format_Command (Expression_Tree_Context &, 
                  std::string new_format);

  /// Set the desired format.
  bool execute () override;

  /// Print the valid commands available to users.
  void print_valid_commands () override;

private:
  /// Requested format.
  std::string format_;
};

/**
 * @class Expr_Command
 * @brief Set the desired expression, e.g., "1+2*3".
 */
class Expr_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and the requested expression.
  Expr_Command (Expression_Tree_Context &, 
                std::string new_expr);

  /// Create the desired expression tree.
  bool execute () override;

  /// Print the valid commands available to users.
  void print_valid_commands () override;

private:
  /// Requested expression.
  std::string expr_;
};

/**
 * @class Print_Command
 * @brief Prints the expression tree in the desired format, e.g.,
 *        "in-order," "pre-order," "post-order", or "level-order".
 */
class Print_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and the requested format.
  Print_Command (Expression_Tree_Context &, 
                 std::string print_format);

  /// Print the expression tree.
  bool execute () override;

  /// Print the valid commands available to users.
  void print_valid_commands () override;

private:
  /// Format to print out the tree.
  std::string format_;
};

/**
 * @class Eval_Command
 * @brief Evaluates the expression tree in the desired format, e.g.,
 *        "in-order," "pre-order," "post-order", or "level-order".
 */
class Eval_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and the requested format.
  Eval_Command (Expression_Tree_Context &, 
                std::string eval_format);

  /// Evaluate the expression tree.
  bool execute () override;
  void print_valid_commands () override;

private:
  /// Format to use for the evaluation.
  std::string format_;
};

/**
 * @class Set_Command
 * @brief Sets a variable into the Interpreter_Context stored
 *        inside of Expression_Tree_Context.
 */
class Set_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and the requested format.
  Set_Command (Expression_Tree_Context &context, 
                std::string key_value_pair);

  /// Evaluate the expression tree.
  bool execute () override;
  void print_valid_commands () override;

private:
  /// Format to use for the evaluation.
  std::string key_value_pair_;
};

/**
 * @class Quit_Command
 * @brief Instructs the event loop to shut down.
 */
class Quit_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context.
  explicit Quit_Command (Expression_Tree_Context &);

  /// Quit the event loop.
  bool execute () override;

  /// Print the valid commands available to users.
  void print_valid_commands () override;
};

/**
 * @class Macro_Command
 * @brief Execute a sequence of commands.
 */
class Macro_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and sequence of commands.
  Macro_Command (Expression_Tree_Context &,
                 std::vector <Expression_Tree_Command> macro_commands);

  /// Quit the event loop.
  bool execute () override;

  /// Print the valid commands available to users.
  void print_valid_commands () override;

private:
  /// Vector of commands that are executed as a macro.
  std::vector <Expression_Tree_Command> macro_commands_;

  /// Expression input by the user.
  std::string expr_;
};

/**
 * @class Null_Command
 * @brief No-op command
 */
class Null_Command : public Expression_Tree_Command_Impl
{
public:
  /// Constructor that provides the appropriate @a
  /// Expression_Tree_Context and the requested format.
  explicit Null_Command (Expression_Tree_Context &context);

  /// Set the desired format.
  bool execute () override;

  /// Print the valid commands available to users.
  void print_valid_commands () override;
};

#endif /* _EXPRESSION_TREE_COMMAND_IMPL_H_ */
