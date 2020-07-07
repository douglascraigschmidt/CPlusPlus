/* -*- C++ -*- */
#include <iostream>
#include <cstdlib>

#include "composites/Component_Node.h"
#include "visitors/Visitor.h"
#include "Leaf_Node.h"

// Ctor
Leaf_Node::Leaf_Node (int item)
  : Component_Node (),
    item_ (item) {
}

// Ctor
Leaf_Node::Leaf_Node (const std::string &item)
  : Component_Node () {
  item_ = ::atoi (item.c_str ());
}

// Ctor
Leaf_Node::Leaf_Node (const char *item)
  : Component_Node () {
  item_ = ::atoi (item);
}

// Dtor
Leaf_Node::~Leaf_Node () = default;

// return the item
int
Leaf_Node::item () const {
  return item_;
}

void 
Leaf_Node::accept (Visitor &visitor) const {
  visitor.visit (*this);
}
