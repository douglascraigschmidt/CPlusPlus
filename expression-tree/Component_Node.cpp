/* -*- C++ -*- */

#ifndef _COMPONENT_NODE_CPP_
#define _COMPONENT_NODE_CPP_

#include <stdexcept>

#include "Component_Node.h"
#include "Visitor.h"

// Dtor
Component_Node::~Component_Node (void)
{
}

int
Component_Node::item (void) const
{
  throw Invalid_Function_Call ("Component_Node::item() called improperly");
  return 0;
}

// default left is to return a null pointer
Component_Node *
Component_Node::left (void) const
{
  return 0;
}

// default right is to return a null pointer
Component_Node *
Component_Node::right (void) const
{
  return 0;
}

// accept a visitor
void 
Component_Node::accept (Visitor &visitor) const
{
  throw Invalid_Function_Call ("Component_Node::accept() called improperly");
}

#endif /* _COMPONENT_NODE_CPP_ */
