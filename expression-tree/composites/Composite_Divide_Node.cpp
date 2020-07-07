/* -*- C++ -*- */
#include <iostream>

#include "Composite_Binary_Node.h"
#include "Composite_Divide_Node.h"
#include "visitors/Visitor.h"

// Ctor
Composite_Divide_Node::Composite_Divide_Node (Component_Node *left, 
                          Component_Node *right)
  : Composite_Binary_Node (left, right) {    
}

// Dtor
Composite_Divide_Node::~Composite_Divide_Node () {
}

int
Composite_Divide_Node::item () const {
  return '/';
}

// accept a visitor
void 
Composite_Divide_Node::accept (Visitor &visitor) const {
  visitor.visit (*this);
}
