/* -*- C++ -*- */
#include <iostream>

#include "Component_Node.h"
#include "Composite_Unary_Node.h"
#include "visitors/Visitor.h"
#include "Composite_Negate_Node.h"

// Ctor

Composite_Negate_Node::Composite_Negate_Node (Component_Node *right)
  : Composite_Unary_Node (right) {
}

// Dtor
Composite_Negate_Node::~Composite_Negate_Node () = default;

int
Composite_Negate_Node::item () const {
  return '-';
}

// accept a visitor
void 
Composite_Negate_Node::accept (Visitor &visitor) const {
  visitor.visit (*this);
}
