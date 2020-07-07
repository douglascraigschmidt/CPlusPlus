/* -*- C++ -*- */
#ifndef _COMPOSITE_NEGATE_NODE_H
#define _COMPOSITE_NEGATE_NODE_H

#include "Composite_Unary_Node.h"

class Component_Node;
class Visitor;

/**
 * @class Composite_Negate_Node
 *
 * @brief A composite node containing only a right child. 
 *        The meaning of this node is -right, eg -5, -7, etc.
 */
class Composite_Negate_Node : public Composite_Unary_Node {
public:
  /// Ctor
  explicit Composite_Negate_Node (Component_Node *right);

  /// Dtor
  ~Composite_Negate_Node () override;

  /// Return the printable character stored in the node.
  [[nodiscard]] int item () const override;

  /// Define the @a accept() operation used for the Visitor pattern.
  void accept (Visitor &visitor) const override;
};

#endif /* _COMPOSITE_NEGATE_NODE_H_ */
