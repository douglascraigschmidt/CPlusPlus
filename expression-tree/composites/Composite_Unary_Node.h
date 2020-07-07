/* -*- C++ -*- */
#ifndef _COMPOSITE_UNARY_NODE_H
#define _COMPOSITE_UNARY_NODE_H

#include "Component_Node.h"

/**
 * @class Composite_Unary_Node
 * *
 * @brief Defines a right child (but not a left one) and thus is useful for unary operations.
 * @see Composite_Binary_Node
 */
class Composite_Unary_Node : public Component_Node
{
public:
  /// Ctor
  explicit Composite_Unary_Node (Component_Node *right);

  /// Return the right child.
  [[nodiscard]] Component_Node *right () const override;

  /// Dtor
  ~Composite_Unary_Node () override;

private:
  /// Right child
  std::unique_ptr<Component_Node> right_;
};

#endif /* _COMPOSITE_UNARY_NODE_H */
