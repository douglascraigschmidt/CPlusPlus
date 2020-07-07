/* -*- C++ -*- */
#ifndef _COMPOSITE_ADD_NODE_H
#define _COMPOSITE_ADD_NODE_H

#include "Composite_Binary_Node.h"

// Forward declaration.
class Component_Node;
class Visitor;

/**
 * @class Composite_Add_Node
 *
 * @brief A composite node containing left and right children. The
 *        meaning of this node is left + right.
 */
class Composite_Add_Node : public Composite_Binary_Node {
public:
  /// Ctor
  Composite_Add_Node (Component_Node *left, 
                      Component_Node *right);

  /// Return the printable character stored in the node.
  [[nodiscard]] int item () const override;

  /// Define the @a accept() operation used for the Visitor pattern.
  void accept (Visitor &visitor) const override;
};

#endif /* _COMPOSITE_ADD_NODE_H */
