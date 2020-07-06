/* -*- C++ -*- */
#ifndef _EVALUATION_VISITOR_CPP_
#define _EVALUATION_VISITOR_CPP_

#include <iostream>

#include "composites/Leaf_Node.h"
#include "composites/Composite_Negate_Node.h"
#include "composites/Composite_Add_Node.h"
#include "composites/Composite_Subtract_Node.h"
#include "composites/Composite_Divide_Node.h"
#include "composites/Composite_Multiply_Node.h"

#include "visitors/Evaluation_Visitor.h"

/// base evaluation for a node. This is used by Leaf_Node
void 
Evaluation_Visitor::visit (const Leaf_Node &node)
{
  stack_.push (node.item ());
}

/// evaluation of a negation (Composite_Negate_Node)
void 
Evaluation_Visitor::visit (const Composite_Negate_Node &node)
{
  if (!stack_.empty()) {
      auto arg = stack_.top();
      stack_.pop();
      stack_.push(-arg);
  }
}

/// evaluation of an addition (Composite_Add_Node)
void 
Evaluation_Visitor::visit (const Composite_Add_Node &node)
{
  if (stack_.size () >= 2) {
      auto rhs = stack_.top();
      stack_.pop();
      auto lhs = stack_.top();
      stack_.pop();
      stack_.push(lhs + rhs);
  }
  // std::cout << "add current top: " << stack_.top () << std::endl;
}

/// evaluation of an addition (Composite_Subtract_Node)
void 
Evaluation_Visitor::visit (const Composite_Subtract_Node &node)
{
  if (stack_.size () >= 2)
    {
      auto rhs = stack_.top ();
      stack_.pop ();
      auto lhs = stack_.top ();
      stack_.pop ();
      stack_.push (lhs - rhs);
    }
}

/// evaluations of a division (Composite_Divide_Node)
void 
Evaluation_Visitor::visit (const Composite_Divide_Node &node)
{
  if (stack_.size () >= 2 && stack_.top ())
    {
      auto rhs = stack_.top ();
      stack_.pop ();
      auto lhs = stack_.top ();
      stack_.pop ();
      stack_.push (lhs / rhs );
    }
  else
    {
      std::cout << "\n\n**ERROR**: Division by zero is not allowed. ";
      std::cout << "Resetting evaluation visitor.\n\n";
      reset ();
    }
}

/// evaluations of a division (Composite_Multiply_Node)
void 
Evaluation_Visitor::visit (const Composite_Multiply_Node &node)
{
  if (stack_.size () >= 2) {
      auto rhs = stack_.top ();
      stack_.pop ();
      auto lhs = stack_.top ();
      stack_.pop ();
      stack_.push(lhs * rhs);
  }
}

/// print a total for the evaluation
int 
Evaluation_Visitor::total ()
{
  if (!stack_.empty ())
    return stack_.top ();
  else
    return 0;
}

/// reset the evaluation
void 
Evaluation_Visitor::reset ()
{
  // Reset the stack to 0.
  stack_ = std::stack<int>();
}

#endif /* _EVALUATION_VISITOR_CPP_ */
