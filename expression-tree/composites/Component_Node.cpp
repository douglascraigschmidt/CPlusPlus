/* -*- C++ -*- */
#include <stdexcept>

#include "Component_Node.h"
#include "visitors/Visitor.h"

// Dtor
Component_Node::~Component_Node (void) = default;

int
Component_Node::get_type () const {
  return type_;
}

int
Component_Node::item () const {
  throw Invalid_Function_Call ("Component_Node::item() called improperly");
  return 0;
}

// default left is to return a null pointer
Component_Node *
Component_Node::left () const {
  return nullptr;
}

// default right is to return a null pointer
Component_Node *
Component_Node::right () const {
  return nullptr;
}

// accept a visitor
void 
Component_Node::accept (Visitor &visitor) const {
  throw Invalid_Function_Call ("Component_Node::accept() called improperly");
}
