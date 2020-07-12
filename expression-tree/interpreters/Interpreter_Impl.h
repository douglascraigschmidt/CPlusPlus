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
  [[nodiscard]] int get (const std::string& variable) const;

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
  explicit Interpreter_Impl(const Interpreter_Context &);

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
  virtual Expression_Tree build_expression_tree (Expr *parse_tree);

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
  explicit In_Order_Interpreter (const Interpreter_Context &context);

  /// Destructor.
  ~In_Order_Interpreter () override;

  /// Return the root of a parse tree corresponding to the @a input.
  Expr *build_parse_tree(const std::string &input) override;

private:
  Expr *make_unary_expr(std::stack<Expr *> &handle_stack,
                        Expr *expr);

  Expr *make_binary_expr(std::stack<Expr *> &handle_stack,
                         Expr *expr);

  /**
   * @class In_Order_Iterator
   *
   * @brief Iterates through the user input expression and converts it
   * into a parse tree.
   */
  class In_Order_Iterator 
    : public std::iterator <std::forward_iterator_tag, Expr *> {
  public:
    /// Constructor that initializes the iterator.
    In_Order_Iterator (const std::string &input);

    /// No-op constructor (corresponds to the "end" of the iteration).
    In_Order_Iterator ();

    /// Inequality operator.
    bool operator != (const In_Order_Iterator &rhs);

    /// Dereference operator.
    Expr *operator *();

    /// Advance the iterator by one.
    void operator++ ();

  private:
    /// Factory method that makes a number (terminal expression).
    Expr *make_number();

    /// Current index into the user input expression. 
    int index_;
  
    /// Pointer to the user input expression.
    const std::string *input_;

    /// Pointer to the prior Expr.
    Expr *prior_expr_;
  };

  /// Factory method that creates the first In_Order_Iterator.
  static In_Order_Iterator begin(const std::string &input);

  /// Factory method that creates the last In_Order_Iterator.
  static In_Order_Iterator end();
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
  explicit Post_Order_Interpreter (const Interpreter_Context &context);

  /// destructor
  ~Post_Order_Interpreter () override;

  /// Return the root of a parse tree corresponding to the @a input.
  Expr *build_parse_tree(const std::string &input) override;

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
    template <typename T> Expr *make_expr(Expr *right_expr);

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
