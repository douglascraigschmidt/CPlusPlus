/* -*- C++ -*- */
#ifndef _EXPR_H
#define _EXPR_H

/**
 * @class Expr
 * @brief Abstract base class of all parse tree nodes.
 */
class Expr
{
public:
  /// constructor
  Expr (Expr *left, Expr *right, int precedence_ = 0);

  /// destructor
  virtual ~Expr ();

  /// abstract method for returning precedence level (higher
  /// value means higher precedence
  virtual int precedence () {
    return precedence_;
  }

  virtual int add_precedence (int accumulated_precedence) = 0;

  /// abstract method for building an Expression Expression_Tree Node

  virtual Component_Node *build () = 0;

  /// left and right pointers

  Expr *left_;
  Expr *right_;
  int precedence_;
};

/**
 * @class Binary_Expr
 * @brief Abstract base class for all parse tree node operators
 * @see   Add_Expr, Subtract_Expr, Multiply_Expr, Divide_Expr
 */
class Binary_Expr : public Expr
{
public:
  /// constructor
  Binary_Expr (Expr *left, Expr *right, int precedence_ = 1);

  /// destructor
  ~Binary_Expr () override;
};

/**
 * @class Unary_Expr
 * @brief Abstract base class for all parse tree node operators
 * @see   Add_Expr, Subtract_Expr, Multiply_Expr, Divide_Expr
 */
class Unary_Expr : public Expr
{
public:
  /// constructor
  explicit Unary_Expr (Expr *right, int precedence_ = 1);

  /// destructor
  ~Unary_Expr () override;
};

/**
 * @class Number_Expr
 * @brief Leaf node of parse tree
 */

class Number_Expr : public Expr
{
public:
  /// constructors
  explicit Number_Expr (const std::string& input);
  explicit Number_Expr (int input);

  /// destructor
  ~Number_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
private:
  /// contains the value of the leaf node
  int number_;
};

/**
 * @class Subtract_Expr
 * @brief Subtraction node of the parse tree
 */

class Subtract_Expr : public Binary_Expr
{
public:
  /// constructor
  Subtract_Expr ();

  Subtract_Expr(Expr *left, Expr *right);

  /// destructor
  ~Subtract_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Add_Expr
 * @brief Addition node of the parse tree
 */

class Add_Expr : public Binary_Expr
{
public:
  /// constructor
  Add_Expr ();

  Add_Expr(Expr *left, Expr *right);

  /// destructor
  ~Add_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Negate_Expr
 * @brief Negate_Expr node of the parse tree
 */

class Negate_Expr : public Unary_Expr
{
public:
  /// constructor
  Negate_Expr ();

  explicit Negate_Expr (Expr *right);

  /// destructor
  ~Negate_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Multiply_Expr
 * @brief Multiplication node of the parse tree
 */

class Multiply_Expr : public Binary_Expr
{
public:
  /// constructor
  Multiply_Expr ();

  Multiply_Expr(Expr *left, Expr *right);

  /// destructor
  ~Multiply_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

/**
 * @class Divide_Expr
 * @brief Division node of the parse tree
 */

class Divide_Expr : public Binary_Expr
{
public:
  /// constructor
  Divide_Expr ();

  Divide_Expr(Expr *left, Expr *right);

  /// destructor
  ~Divide_Expr () override;

  /// returns the precedence level
  //virtual int precedence (void);
  int add_precedence (int accumulated_precedence) override;

  /// builds an equivalent Expression_Tree node
  Component_Node *build () override;
};

#endif /* _EXPR_H */
