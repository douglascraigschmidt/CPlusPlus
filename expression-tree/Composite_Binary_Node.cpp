/* -*- C++ -*- */
#ifndef _COMPOSITE_LR_NODE_CPP_
#define _COMPOSITE_LR_NODE_CPP_

#include "Composite_Binary_Node.h"

// Ctor
Composite_Binary_Node::Composite_Binary_Node (Component_Node *left,
                                              Component_Node *right)
  : Composite_Unary_Node (right), 
    left_ (left)
{    
}

// Dtor
Composite_Binary_Node::~Composite_Binary_Node (void)
{
}


// Return the left child pointer
Component_Node *
Composite_Binary_Node::left (void) const
{
  return left_.get ();
}


#endif /* _COMPOSITE_LR_NODE_CPP_ */
