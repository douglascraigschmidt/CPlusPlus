/* -*- C++ -*- */
#include <iostream>

#include "Component_Node.h"
#include "visitors/Visitor.h"
#include "Composite_Add_Node.h"

// Ctor

Composite_Add_Node::Composite_Add_Node (Component_Node *left,
                    Component_Node *right)
  : Composite_Binary_Node (left, right) {    
}

int
Composite_Add_Node::item () const {
  return '+';
}

// accept a visitor

void 
Composite_Add_Node::accept (Visitor &visitor) const {
  visitor.visit (*this);
}
