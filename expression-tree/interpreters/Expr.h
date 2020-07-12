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
  explicit Expr (int symbol_type);

  /// destructor
  virtual ~Expr ();

  /// abstract method for building an Expression Expression_Tree Node
  [[nodiscard]] virtual Component_Node *build () const;

  /// abstract method for interpreting an Expression Expression_Tree Node
  [[nodiscard]] virtual int interpret() const;

  /// returns the symbol type.
  [[nodiscard]] int get_type() const;

protected:
  int symbol_type_;
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
  Binary_Expr (Expr *left, 
               Expr *right, 
               int symbol_type);

  ~Binary_Expr() override;

    Expr *right_expr_;
/// left and right pointers
Expr *left_expr_;
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

  /// builds an equivalent Expression_Tree node
  [[nodiscard]] Component_Node *build () const override;

  /// Method for interpreting this node.
  [[nodiscard]] int interpret() const override;

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

  /// builds an equivalent Expression_Tree node
  [[nodiscard]] Component_Node *build () const override;

  /// Method for interpreting this node.
  [[nodiscard]] int interpret() const override;
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

  /// builds an equivalent Expression_Tree node
  [[nodiscard]] Component_Node *build () const override;

  /// Method for interpreting this node.
  [[nodiscard]] int interpret() const override;
};

/**
 * @class Negate_Expr
 * @brief Negate_Expr node of the parse tree
 */

class Negate_Expr : public Expr
{
public:
  explicit Negate_Expr (Expr *right = nullptr);

  /// builds an equivalent Expression_Tree node
  [[nodiscard]] Component_Node *build () const override;

  /// Method for interpreting this node.
  [[nodiscard]] int interpret() const override;

    Expr *right_expr_;

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

  /// builds an equivalent Expression_Tree node
  [[nodiscard]] Component_Node *build () const override;

  /// Method for interpreting this node.
  [[nodiscard]] int interpret() const override;
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

  /// builds an equivalent Expression_Tree node
  [[nodiscard]] Component_Node *build () const override;

  /// Method for interpreting this node.
  [[nodiscard]] int interpret() const override;
};

/**
 * @class Left_Paren
 * @brief A parse tree node that handles the left-paren terminal expression.
 */
class Left_Paren : public Expr
{
public:
  /// constructor
  Left_Paren ();
};

/**
 * @class Right_Paren
 * @brief A parse tree node that handles the right-paren terminal expression.
 */
class Right_Paren : public Expr
{
public:
  /// constructor
  Right_Paren ();
};

/**
 * @class Delimiter @brief A parse tree node that handles the
 * beginning-of-input and end-of-input delimiters.
 */
class Delimiter : public Expr
{
public:
  /// constructor
  Delimiter ();
};

#endif /* _EXPR_H */
