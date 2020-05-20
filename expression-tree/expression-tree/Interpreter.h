#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include <string>
#include <list>
#include <map>

#include "Expression_Tree.h"

// Forward declaration.
class Symbol;

/**
 * @class Interpreter_Context
 * @brief This class stores variables and their values for use by the Interpreters.
 *
 *        This class plays the role of the "context" in the Interpreter pattern.
 */
class Interpreter_Context
{
public:
  /// Constructor.
  Interpreter_Context (void);

  /// Destructor.
  ~Interpreter_Context (void);

  /// Return the value of a variable.
  int get (std::string variable);

  /// Set the value of a variable.
  void set (std::string variable, int value);

  /// Print all variables and their values.
  void print (void);

  /// Clear all variables and their values.
  void reset (void);

private:
  /// Hash table containing variable names and values.
  std::map<std::string, int> map_;
};

/**
 * @class Interpreter
 * @brief Parses incoming expression strings into a parse tree and
 *        generates an expression tree from the parse tree.
 *
 *        This class plays the role of the "interpreter" in the
 *        Intepreter pattern.  It also uses the Builder pattern to
 *        generate the nodes in the expression tree.
 */
class Interpreter
{
public:
  /// Constructor.
  Interpreter (void);

  /// destructor
  virtual ~Interpreter (void);

  /// Converts a string and context into a parse tree, and builds an
  /// expression tree out of the parse tree.
  Expression_Tree interpret (Interpreter_Context &context, 
                             const std::string &input);

  /// Method for checking if a character is a valid operator.
  static bool is_operator (char input);

  /// Method for checking if a character is a number.
  static bool is_number (char input);
  
  /// Method for checking if a character is a candidate for a part of
  /// a variable name.
  static bool is_alphanumeric (char input);

private:
  /// Inserts a terminal into the parse tree.
  void terminal_insert (Symbol *op,
                       std::list<Symbol *>& list);

  /// Inserts a variable (leaf node / number) into the parse tree.
  void variable_insert (Interpreter_Context &context,
                        const std::string &input,
                        std::string::size_type &i,
                      int & accumulated_precedence,
                      std::list<Symbol *>& list,
                       Symbol *& lastValidInput);

  /// Inserts a leaf node / number into the parse tree.
  void number_insert (const std::string &input, 
                      std::string::size_type &i,
                      int & accumulated_precedence,
                      std::list<Symbol *>& list,
                       Symbol *& lastValidInput);

  /// Inserts a multiplication or division into the parse tree.
  void precedence_insert (Symbol *op, std::list<Symbol *>& list);

  void main_loop (Interpreter_Context & context,
                       const std::string &input,
                       std::string::size_type &i,
                       Symbol *& lastValidInput,
                       bool & handled,
                       int & accumulated_precedence,
                       std::list<Symbol *>& list);

  void handle_parenthesis (Interpreter_Context & context,
                       const std::string &input,
                       std::string::size_type &i,
                       Symbol *& lastValidInput,
                       bool & handled,
                       int & accumulated_precedence,
                       std::list<Symbol *>& list);

  /// Stores the parse tree. isn't entirely necessary right now, but
  /// is kept as a list for future expansion (parentheses).
  //std::list<Symbol *> list_;
};

#endif /* _INTERPRETER_H_ */
