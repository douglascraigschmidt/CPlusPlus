/* -*- C++ -*- */
#ifndef _INTERPRETER_IMPL_H
#define _INTERPRETER_IMPL_H

#include <string>
#include <list>
#include <map>
#include <stack>

#include "trees/Expression_Tree.h"
#include "interpreters/Expr.h"

/**
 * @class Interpreter_Context
 *
 * @brief This class stores variables and their values for use by the
 *        Interpreters.
 *
 *        This class plays the role of the "context" in the
 *        Interpreter pattern.
 */
class Interpreter_Context {
public:
  /// Constructor.
  Interpreter_Context ();

  /// Destructor.
  ~Interpreter_Context ();

  /// Return the value of a variable.
  int get (const std::string& variable) const;

  /// Set the value of a variable.
  void set (const std::string& variable, int value);

  /// Print all variables and their values.
  void print () const;

  /// Clear all variables and their values.
  void reset ();

private:
  /// Hash table containing variable names and values.
  std::map<std::string, int> map_;
};

/**
 * @class Interpreter_Impl
 *
 * @brief Plays the role of the "implementor" base class in the Bridge
 *        pattern that is used as the basis for the subclasses that
 *        actually define the various interpreters.

 */
class Interpreter_Impl {
public:
  Interpreter_Impl(const Interpreter_Context &);

  /// Converts a string into a parse tree and builds an expression
  /// tree out of the parse tree.
  virtual Expression_Tree interpret (const std::string &input);

  /// Destructor.
  virtual ~Interpreter_Impl();

protected:
  /// Return the root of a parse tree corresponding to the @a input.
  virtual Expr *build_parse_tree(const std::string &input) = 0;

  /// This hook method can be overridden to conduct optimization on
  /// the @a parse_tree prior to generating the @a Expression_Tree.
  /// By default it's a no-op.
  virtual void optimize_parse_tree (Expr *parse_tree);

  /// Invoke a recursive build of the @a Expression_Tree, starting
  /// with the root expression of the parse tree.  The Builder pattern
  /// is used at each node to create the appropriate subclass of @
  /// Component_Node.
  virtual Expression_Tree build_expression_tree (Expr *parse_tree) = 0;

  /// Plays the context role in the Interpreter pattern.
  const Interpreter_Context &context_;
};

/**
 * @class In_Order_Interpreter
 * 
 * @brief Parses incoming in-order expression strings into a parse
 *        tree and generates an expression tree from the parse tree.
 *
 *        This class plays the role of the "interpreter" in the
 *        Intepreter pattern.  It also uses the Builder pattern to
 *        generate the nodes in the expression tree.
 */
class In_Order_Interpreter : public Interpreter_Impl
{
public:
  /// Constructor.
  In_Order_Interpreter (const Interpreter_Context &context);

  /// Destructor.
  ~In_Order_Interpreter () override;

  /// Return the root of a parse tree corresponding to the @a input.
  Expr *build_parse_tree(const std::string &input) override;

  /// Invoke a recursive build of the @a Expression_Tree, starting
  /// with the root expression of the parse tree.  The Builder pattern
  /// is used at each node to create the appropriate subclass of @
  /// Component_Node.
  Expression_Tree build_expression_tree (Expr *parse_tree) override;

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

  /// Run the main loop of the interpreter.
  void main_loop (const std::string &input,
                  std::string::size_type &i,
                  Expr *& lastValidInput,
                  bool & handled,
                  int & accumulated_precedence,
                  std::list<Expr *>& list);

  /// Inserts parentheses into the parse tree.
  void handle_parenthesis (const std::string &input,
                           std::string::size_type &i,
                           Expr *& lastValidInput,
                           bool & handled,
                           int & accumulated_precedence,
                           std::list<Expr *>& list);
};

/**
 * @class Post_Order_Interpreter
 *
 * @brief Parses incoming post-order expression strings into a parse
 *        tree and generates an expression tree from the parse tree.
 *
 *        This class plays the role of the "interpreter" in the
 *        Intepreter pattern.  It also uses the Builder pattern to
 *        generate the nodes in the expression tree.
 */
class Post_Order_Interpreter : public Interpreter_Impl {
public:
  /// Constructor.
  Post_Order_Interpreter (const Interpreter_Context &context);

  /// destructor
  ~Post_Order_Interpreter () override;

  /// Return the root of a parse tree corresponding to the @a input.
  Expr *build_parse_tree(const std::string &input) override;

  /// Invoke a recursive build of the @a Expression_Tree, starting
  /// with the root expression of the parse tree.  The Builder pattern
  /// is used at each node to create the appropriate subclass of @
  /// Component_Node.
  Expression_Tree build_expression_tree (Expr *parse_tree) override;

private:
  /**
   * @class Post_Order_Iterator
   *
   * @brief Iterates through the user input expression and converts it
   * into a parse tree.
   */
  class Post_Order_Iterator 
    : public std::iterator <std::forward_iterator_tag, Expr *> {
  public:
    /// Constructor that initializes the iterator.
    Post_Order_Iterator (const std::string &input, std::stack<Expr *> &stack);

    /// No-op constructor (corresponds to the "end" of the iteration).
    Post_Order_Iterator ();

    /// Inequality operator.
    bool operator != (const Post_Order_Iterator &rhs);

    /// Dereference operator.
    Expr *operator *();

    /// Advance the iterator by one.
    void operator++ ();

  private:
    /// Factory method that makes a number (terminal expression).
    Expr *make_number();

    /// Factory method that makes a non-terminal expression (e.g.,
    /// Add_Expr, Multiply_Expr, etc.).
    template <typename T> Expr *
    make_expr(std::stack<Expr *> *stack, Expr *right_expr);

    /// Current index into the user input expression. 
    int index_;
  
    /// Pointer to the user input expression.
    const std::string *input_;

    /// Pointer to the stack representing the parse tree nodes.
    std::stack<Expr *> *stack_;
  };

  /// Factory method that creates the first Post_Order_Iterator.
  static Post_Order_Iterator begin(const std::string &input,
                                   std::stack<Expr *> &stack);


  /// Factory method that creates the last Post_Order_Iterator.
  static Post_Order_Iterator end();
};

#endif /* _INTERPRETER_IMPL_H */
