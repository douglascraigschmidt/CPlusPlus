/* -*- C++ -*- */
#ifndef _PRINT_VISITOR_CPP_
#define _PRINT_VISITOR_CPP_

#include <iostream>

#include "Leaf_Node.h"
#include "Composite_Negate_Node.h"
#include "Composite_Add_Node.h"
#include "Composite_Subtract_Node.h"
#include "Composite_Divide_Node.h"
#include "Composite_Multiply_Node.h"
#include "Print_Visitor.h"

/// visit function - prints Leaf_Negate_Node contents to std::cout

void 
Print_Visitor::visit (const Leaf_Node &node)
{
  std::cout << node.item () << " ";
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
