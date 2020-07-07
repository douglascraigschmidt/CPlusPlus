/* -*- C++ -*- */
#include <iostream>

#include "Component_Node.h"
#include "Composite_Binary_Node.h"
#include "Composite_Multiply_Node.h"
#include "visitors/Visitor.h"

// Ctor
Composite_Multiply_Node::Composite_Multiply_Node (Component_Node * left,
                                                  Component_Node * right)
  : Composite_Binary_Node (left, right) {    
}

// Dtor
Composite_Multiply_Node::~Composite_Multiply_Node () = default;

int
Composite_Multiply_Node::item () const {
  return '*';
}

// accept a visitor
void 
Composite_Multiply_Node::accept (Visitor& visitor) const {
  visitor.visit (*this);
}
