/* -*- C++ -*- */
#ifndef _COMPOSITE_UNARY_NODE_H_
#define _COMPOSITE_UNARY_NODE_H_

#include "Component_Node.h"

/**
 * @class Composite_Unary_Node
 * @brief Defines a right child (but not a left one) and thus is useful for unary operations.
 * @see Composite_Binary_Node
 */
class Composite_Unary_Node : public Component_Node
{
public:
  /// Ctor
  Composite_Unary_Node (Component_Node *right);

  /// Return the right child.
  virtual Component_Node *right (void) const;

  /// Dtor
  virtual ~Composite_Unary_Node (void);

private:
  /// Right child
  std::auto_ptr<Component_Node> right_;
};

#endif /* _COMPOSITE_UNARY_NODE_H_ */
