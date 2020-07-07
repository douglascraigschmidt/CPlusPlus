/* -*- C++ -*- */

#include "Composite_Binary_Node.h"

// Ctor
Composite_Binary_Node::Composite_Binary_Node (Component_Node *left,
                                              Component_Node *right)
  : Composite_Unary_Node (right), 
    left_ (left) {    
}

// Dtor
Composite_Binary_Node::~Composite_Binary_Node () = default;


// Return the left child pointer
Component_Node *
Composite_Binary_Node::left () const {
  return left_.get ();
}
