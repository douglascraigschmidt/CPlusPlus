/* -*- C++ -*- */
#ifndef _COMPOSITE_BINARY_NODE_H
#define _COMPOSITE_BINARY_NODE_H

#include <string>

#include "Composite_Unary_Node.h"

/**
 * @class Composite_Binary_Node
 *
 * @brief Defines a left and right node (via inheritance).
 */
class Composite_Binary_Node : public Composite_Unary_Node {
public:
  /// Ctor
  Composite_Binary_Node (Component_Node *left,
                         Component_Node *right);

  /// Dtor
  ~Composite_Binary_Node () override;

  /// Return the left child.
  [[nodiscard]] Component_Node *left () const override;

private:
  /// left child
  std::unique_ptr<Component_Node> left_;
};

#endif /* _COMPOSITE_BINARY_NODE_H */
