/* -*- C++ -*- */
#ifndef _PRINT_VISITOR_CPP_
#define _PRINT_VISITOR_CPP_

#include <iostream>

#include "composites/Leaf_Node.h"
#include "composites/Composite_Negate_Node.h"
#include "composites/Composite_Add_Node.h"
#include "composites/Composite_Subtract_Node.h"
#include "composites/Composite_Divide_Node.h"
#include "composites/Composite_Multiply_Node.h"
#include "visitors/Print_Visitor.h"

/// visit function - prints Leaf_Negate_Node contents to std::cout

void 
Print_Visitor::visit (const Leaf_Node &node)
{
  std::cout << " " << node.item ();
}

/// visit function - prints Composite_Negate_Node contents to std::cout

void 
Print_Visitor::visit (const Composite_Negate_Node &node)
{
  std::cout.put ('-');
}

/// visit function - prints Composite_Add_Node contents to std::cout

void 
Print_Visitor::visit (const Composite_Add_Node &node)
{
  std::cout << "+ ";
}

/// visit function - prints Composite_Subtract_Node contents to std::cout

void 
Print_Visitor::visit (const Composite_Subtract_Node &node)
{
  std::cout << "- ";
}

/// visit function - prints Composite_Divide_Node contents to std::cout

void 
Print_Visitor::visit (const Composite_Divide_Node &node)
{
  std::cout << "/ ";
}

/// visit function - prints Composite_Multiply_Node contents to std::cout

void 
Print_Visitor::visit (const Composite_Multiply_Node &node)
{
  std::cout << "* ";
}

#endif /* _PRINT_VISITOR_CPP_ */
