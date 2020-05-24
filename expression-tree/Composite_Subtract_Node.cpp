/* -*- C++ -*- */
#ifndef _SUBTRACT_NODE_CPP_
#define _SUBTRACT_NODE_CPP_

#include "Component_Node.h"
#include "Visitor.h"
#include "Composite_Binary_Node.h"
#include "Composite_Subtract_Node.h"

// Ctor
Composite_Subtract_Node::Composite_Subtract_Node (Component_Node *left,
                                                  Component_Node *right)
: Composite_Binary_Node (left, right)
{    
}

// Dtor
Composite_Subtract_Node::~Composite_Subtract_Node (void)
{
}

int
Composite_Subtract_Node::item (void) const
{
  return '-';
}

// accept a visitor
void 
Composite_Subtract_Node::accept (Visitor &visitor) const
{
  visitor.visit (*this);
}

#endif /* _SUBTRACT_NODE_CPP_ */
