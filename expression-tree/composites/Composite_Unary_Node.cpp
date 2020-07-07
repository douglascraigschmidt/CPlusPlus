/* -*- C++ -*- */
#include "Composite_Unary_Node.h"

// Ctor

Composite_Unary_Node::Composite_Unary_Node (Component_Node *right)
  : Component_Node (), 
    right_ (right) {
}

// Dtor
Composite_Unary_Node::~Composite_Unary_Node () = default;

// Return the right child pointer
Component_Node *
Composite_Unary_Node::right () const {
  return right_.get ();
}
