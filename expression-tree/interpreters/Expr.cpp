#include "composites/Component_Node.h"
#include "composites/Leaf_Node.h"
#include "composites/Composite_Negate_Node.h"
#include "composites/Composite_Add_Node.h"
#include "composites/Composite_Subtract_Node.h"
#include "composites/Composite_Divide_Node.h"
#include "composites/Composite_Multiply_Node.h"
#include "interpreters/Expr.h"

// constructor
Expr::Expr (Expr *left, Expr *right, int precedence)
  : left_ (left), right_ (right), precedence_ (precedence)
{
}

// destructor
Expr::~Expr ()
{
  delete left_;
  delete right_;
}

// constructor
Binary_Expr::Binary_Expr (Expr *left, Expr *right, int precedence)
  : Expr (left, right, precedence)
{
}

// destructor
Binary_Expr::~Binary_Expr ()
= default;

// constructor
Unary_Expr::Unary_Expr (Expr *right, int precedence)
  : Expr (nullptr, right, precedence)
{
}

// destructor
Unary_Expr::~Unary_Expr ()
= default;

// constructor
Number_Expr::Number_Expr (const std::string& input)
  : Expr (nullptr, nullptr, 4)
{
  number_ = ::atoi (input.c_str ());
}

// constructor
Number_Expr::Number_Expr (int input)
  : Expr (nullptr, nullptr, 4),
    number_ (input)
{
}

// destructor
Number_Expr::~Number_Expr ()
= default;

// returns the precedence level
int 
Number_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 4 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Number_Expr::build ()
{
  return new Leaf_Node (number_);
}

// constructor
Negate_Expr::Negate_Expr ()
  : Unary_Expr (nullptr, 3)
{
}

Negate_Expr::Negate_Expr (Expr *right)
  : Unary_Expr (right, 3)
{
}

// destructor
Negate_Expr::~Negate_Expr ()
= default;

// returns the precedence level
int 
Negate_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 3 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Negate_Expr::build ()
{
  return new Composite_Negate_Node (right_->build ());
}

// constructor
Add_Expr::Add_Expr ()
  : Binary_Expr (nullptr, nullptr, 1)
{
}

Add_Expr::Add_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right)
{
}

// destructor
Add_Expr::~Add_Expr ()
= default;

// returns the precedence level
int 
Add_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 1 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Add_Expr::build ()
{
  return new Composite_Add_Node (left_->build (), right_->build ());
}

// constructor
Subtract_Expr::Subtract_Expr ()
  : Binary_Expr (nullptr, nullptr, 1)
{
}

Subtract_Expr::Subtract_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right)
{
}

// destructor
Subtract_Expr::~Subtract_Expr ()
= default;

// returns the precedence level
int 
Subtract_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 1 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Subtract_Expr::build ()
{
  return new Composite_Subtract_Node (left_->build (), right_->build ());
}

// constructor
Multiply_Expr::Multiply_Expr ()
  : Binary_Expr (nullptr, nullptr, 2)
{
}

Multiply_Expr::Multiply_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right)
{
}

// destructor
Multiply_Expr::~Multiply_Expr ()
= default;

// returns the precedence level
int 
Multiply_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 2 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Multiply_Expr::build ()
{
  return new Composite_Multiply_Node (left_->build (), right_->build ());
}

// constructor
Divide_Expr::Divide_Expr ()
  : Binary_Expr (nullptr, nullptr, 2)
{
}

Divide_Expr::Divide_Expr (Expr *left, Expr *right)
  : Binary_Expr (left, right)
{
}

// destructor
Divide_Expr::~Divide_Expr ()
= default;

// returns the precedence level
int 
Divide_Expr::add_precedence (int precedence)
{
  return this->precedence_ = 2 + precedence;
}

// builds an equivalent Expression_Tree node
Component_Node *
Divide_Expr::build ()
{
  return new Composite_Divide_Node (left_->build (), right_->build ());
}

