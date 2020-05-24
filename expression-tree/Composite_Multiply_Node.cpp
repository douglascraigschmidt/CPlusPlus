/* -*- C++ -*- */
#ifndef _MULTIPLY_NODE_CPP_
#define _MULTIPLY_NODE_CPP_

#include <iostream>

#include "Component_Node.h"
#include "Composite_Binary_Node.h"
#include "Composite_Multiply_Node.h"
#include "Visitor.h"

// Ctor
Composite_Multiply_Node::Composite_Multiply_Node (Component_Node * left,
                              Component_Node * right)
  : Composite_Binary_Node (left, right)
{    
}

// Dtor
Composite_Multiply_Node::~Composite_Multiply_Node (void)
{
}

int
Composite_Multiply_Node::item (void) const
{
  return '*';
}

// accept a visitor
void 
Composite_Multiply_Node::accept (Visitor& visitor) const
{
  visitor.visit (*this);
}

#endif /* _MULTIPLY_NODE_CPP_ */
