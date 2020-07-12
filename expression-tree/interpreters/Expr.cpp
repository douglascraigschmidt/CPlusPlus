#include <iostream>
#include "composites/Component_Node.h"
#include "composites/Leaf_Node.h"
#include "composites/Composite_Negate_Node.h"
#include "composites/Composite_Add_Node.h"
#include "composites/Composite_Subtract_Node.h"
#include "composites/Composite_Divide_Node.h"
#include "composites/Composite_Multiply_Node.h"
#include "interpreters/Expr.h"

// constructor
Expr::Expr (int symbol_type)
  : symbol_type_(symbol_type)
{
}

// destructor
Expr::~Expr () = default;

int
Expr::get_type() const {
  return symbol_type_;
}

Component_Node *
Expr::build () const {
  return nullptr;
}

int
Expr::interpret () const {
  return 0;
}

// constructor
Binary_Expr::Binary_Expr (Expr *left, Expr *right, 
                          int symbol_type)
  : Expr (symbol_type),
    left_expr_(left), 
    right_expr_(right)
{
}

Binary_Expr::~Binary_Expr() {
  delete left_expr_;
  delete right_expr_;
}

// constructor
Number_Expr::Number_Expr (const std::string& input)
  : Expr (Component_Node::NUMBER)
{
  number_ = ::atoi (input.c_str ());
}

// constructor
Number_Expr::Number_Expr (int input)
  : Expr (Component_Node::NUMBER),
    number_ (input)
{
}

// builds an equivalent Expression_Tree node
Component_Node *
Number_Expr::build () const
{
  return new Leaf_Node (number_);
}

int
Number_Expr::interpret () const
{
  return number_;
}

Negate_Expr::Negate_Expr (Expr *right)
  : Expr (Component_Node::NEGATION), right_expr_(right)
{
}

// builds an equivalent Expression_Tree node
Component_Node *
Negate_Expr::build () const
{
  return new Composite_Negate_Node (right_expr_->build ());
}

int
Negate_Expr::interpret () const
{
  return -right_expr_->interpret ();
}

// constructor
Add_Expr::Add_Expr ()
  : Binary_Expr (nullptr, nullptr, Component_Node::ADDITION)
{
}

Add_Expr::Add_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right, Component_Node::ADDITION)
{
}

// builds an equivalent Expression_Tree node
Component_Node *
Add_Expr::build () const
{
  return new Composite_Add_Node (left_expr_->build (),
                                 right_expr_->build ());
}

int
Add_Expr::interpret () const
{
  return left_expr_->interpret()
    + right_expr_->interpret ();
}

// constructor
Subtract_Expr::Subtract_Expr ()
  : Binary_Expr (nullptr, nullptr, Component_Node::SUBTRACTION)
{
}

Subtract_Expr::Subtract_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right, Component_Node::SUBTRACTION)
{
}

// builds an equivalent Expression_Tree node
Component_Node *
Subtract_Expr::build () const
{
  return new Composite_Subtract_Node (left_expr_->build (),
                                      right_expr_->build ());
}

int
Subtract_Expr::interpret () const
{
  return left_expr_->interpret()
    - right_expr_->interpret ();
}

// constructor
Multiply_Expr::Multiply_Expr ()
  : Binary_Expr (nullptr, nullptr,
                 Component_Node::MULTIPLICATION)
{
}

Multiply_Expr::Multiply_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right,
                 Component_Node::MULTIPLICATION)
{
}

// builds an equivalent Expression_Tree node
Component_Node *
Multiply_Expr::build () const
{
  return new Composite_Multiply_Node (left_expr_->build (),
                                      right_expr_->build ());
}

int
Multiply_Expr::interpret () const
{
  return left_expr_->interpret()
    * right_expr_->interpret ();
}

// constructor
Divide_Expr::Divide_Expr ()
  : Binary_Expr (nullptr, nullptr, 
                 Component_Node::DIVISION)
{
}

Divide_Expr::Divide_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right,
                 Component_Node::DIVISION)
{
}

// builds an equivalent Expression_Tree node
Component_Node *
Divide_Expr::build () const
{
  return new Composite_Divide_Node (left_expr_->build (), 
                                    right_expr_->build ());
}

int
Divide_Expr::interpret () const
{
  return left_expr_->interpret()
    / right_expr_->interpret ();
}

// constructor
Left_Paren::Left_Paren ()
  : Expr (Component_Node::LPAREN)
{
}

Right_Paren::Right_Paren ()
  : Expr (Component_Node::RPAREN)
{
}

Delimiter::Delimiter ()
  : Expr (Component_Node::DELIMITER)
{
}

