/* -*- C++ -*- */
#ifndef _EVALUATION_VISITOR_CPP_
#define _EVALUATION_VISITOR_CPP_

#include <iostream>

#include "Leaf_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Add_Node.h"
#include "Composite_Subtract_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"

#include "Evaluation_Visitor.h"

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
  if (stack_.size () >= 1)
    stack_.push (-stack_.pop ());
}

/// evaluation of an addition (Composite_Add_Node)
void 
Evaluation_Visitor::visit (const Composite_Add_Node &node)
{
  if (stack_.size () >= 2)
    stack_.push (stack_.pop () + stack_.pop ());
  // std::cout << "add current top: " << stack_.top () << std::endl;
}

/// evaluation of an addition (Composite_Subtract_Node)
void 
Evaluation_Visitor::visit (const Composite_Subtract_Node &node)
{
  if (stack_.size () >= 2)
    {
      int rhs = stack_.pop ();
      stack_.push (stack_.pop () - rhs);
    }
}

/// evaluations of a division (Composite_Divide_Node)
void 
Evaluation_Visitor::visit (const Composite_Divide_Node &node)
{
  if (stack_.size () >= 2 && stack_.top ())
    {
      int rhs = stack_.pop ();
      stack_.push (stack_.pop () / rhs );
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
  if (stack_.size () >= 2)
    stack_.push (stack_.pop () * stack_.pop ());
}

/// print a total for the evaluation
int 
Evaluation_Visitor::total (void)
{
  if (!stack_.is_empty ())
    return stack_.top ();
  else
    return 0;
}

/// reset the evaluation
void 
Evaluation_Visitor::reset (void)
{
  stack_.erase ();
}

#endif /* _EVALUATION_VISITOR_CPP_ */
