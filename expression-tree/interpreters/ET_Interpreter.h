#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <string>
#include <list>
#include <map>

#include "trees/Expression_Tree.h"

// Forward declaration.
class Expr;

/**
 * @class ET_Interpreter_Context
 * @brief This class stores variables and their values for use by the Interpreters.
 *
 *        This class plays the role of the "context" in the ET_Interpreter pattern.
 */
class ET_Interpreter_Context
{
public:
  /// Constructor.
  ET_Interpreter_Context ();

  /// Destructor.
  ~ET_Interpreter_Context ();

  /// Return the value of a variable.
  int get (const std::string& variable);

  /// Set the value of a variable.
  void set (const std::string& variable, int value);

  /// Print all variables and their values.
  void print ();

  /// Clear all variables and their values.
  void reset ();

private:
  /// Hash table containing variable names and values.
  std::map<std::string, int> map_;
};

class ET_Interpreter_Impl;

/**
 * @class ET_Interpreter
 * @brief Parses incoming expression strings into a parse tree and
 *        generates an expression tree from the parse tree.
 *
 *        This class plays the role of the "interpreter" in the
 *        Intepreter pattern.  It also uses the Builder pattern to
 *        generate the nodes in the expression tree.
 */
class ET_Interpreter
{
public:
  /// Constructor.
  explicit ET_Interpreter (ET_Interpreter_Impl *impl);

  /// destructor
  virtual ~ET_Interpreter ();

  /// Converts a string and context into a parse tree, and builds an
  /// expression tree out of the parse tree.
  Expression_Tree interpret (const std::string &input);

private:
  Refcounter<ET_Interpreter_Impl> interpreter_;
};

/**
 * @class ET_Interpreter_Impl
 */
class ET_Interpreter_Impl {
public:
  /// Converts a string and context into a parse tree, and builds an
  /// expression tree out of the parse tree.
  virtual Expression_Tree interpret (const std::string &input);

  virtual ~ET_Interpreter_Impl();

protected:
  virtual Expr *build_parse_tree(const std::string &input) = 0;

  virtual void optimize_parse_tree (Expr *parse_tree);

  virtual Expression_Tree build_expression_tree (Expr *parse_tree) = 0;

  ET_Interpreter_Context context_;
};

/**
 * @class ET_In_Order_Interpreter
 * @brief Parses incoming in-order expression strings into a parse
 *        tree and generates an expression tree from the parse tree.
 *
 *        This class plays the role of the "interpreter" in the
 *        Intepreter pattern.  It also uses the Builder pattern to
 *        generate the nodes in the expression tree.
 */
class ET_In_Order_Interpreter : public ET_Interpreter_Impl
{
public:
  /// Constructor.
  ET_In_Order_Interpreter ();

  /// destructor
  virtual ~ET_In_Order_Interpreter ();

  Expr *build_parse_tree(const std::string &input) override;

  /// Converts a string and context into a parse tree, and builds an
  /// expression tree out of the parse tree.
  Expression_Tree build_expression_tree (Expr *parse_tree) override;

  /// Method for checking if a character is a valid operator.
  static bool is_operator (char input);

  /// Method for checking if a character is a number.
  static bool is_number (char input);
  
  /// Method for checking if a character is a candidate for a part of
  /// a variable name.
  static bool is_alphanumeric (char input);

private:
  /// Inserts a terminal into the parse tree.
  static void terminal_insert (Expr *op,
                               std::list<Expr *>& list);

  /// Inserts a variable (leaf node / number) into the parse tree.
  void variable_insert (const std::string &input,
                        std::string::size_type &i,
                        int & accumulated_precedence,
                        std::list<Expr *>& list,
                        Expr *& lastValidInput);

  /// Inserts a leaf node / number into the parse tree.
  static void number_insert (const std::string &input,
                      std::string::size_type &i,
                      int & accumulated_precedence,
                      std::list<Expr *>& list,
                      Expr *& lastValidInput);

  /// Inserts a multiplication or division into the parse tree.
  static void precedence_insert (Expr *op, std::list<Expr *>& list);

  void main_loop (const std::string &input,
                  std::string::size_type &i,
                  Expr *& lastValidInput,
                  bool & handled,
                  int & accumulated_precedence,
                  std::list<Expr *>& list);

  void handle_parenthesis (const std::string &input,
                           std::string::size_type &i,
                           Expr *& lastValidInput,
                           bool & handled,
                           int & accumulated_precedence,
                           std::list<Expr *>& list);
};

#endif /* _INTERPRETER_H_ */
