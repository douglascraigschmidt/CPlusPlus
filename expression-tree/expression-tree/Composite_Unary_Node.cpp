/* -*- C++ -*- */
#ifndef _COMPOSITE_NODE_CPP_
#define _COMPOSITE_NODE_CPP_

#include "Composite_Unary_Node.h"

// Ctor

Composite_Unary_Node::Composite_Unary_Node (Component_Node *right)
  : Component_Node (), 
    right_ (right)
{    
}

// Dtor
Composite_Unary_Node::~Composite_Unary_Node (void)
{
}


// Return the right child pointer
Component_Node *
Composite_Unary_Node::right (void) const
{
  return right_.get ();
}


#endif /* _COMPOSITE_NODE_CPP_ */
