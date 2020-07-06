/* -*- C++ -*- */
#ifndef _LEAF_NODE_H_
#define _LEAF_NODE_H_

#include <string>
#include "composites/Component_Node.h"

// Forward declarations.
class Visitor;

/**
 * @class Leaf_Node
 * @brief Defines a terminal node of type integer. This node inherits
 *        from Node and so has no children.
 */

class Leaf_Node : public Component_Node
{
public:
  /// Ctor.
  explicit Leaf_Node (int item);

  /// Ctor.
  explicit Leaf_Node (const std::string &item);

  /// Ctor.
  explicit Leaf_Node (const char *item);

  /// Dtor.
  ~Leaf_Node () override;

  /// Return the item stored in the node.
  [[nodiscard]] int item () const override;

  /// Define the @a accept() operation used for the Visitor pattern.
  void accept (Visitor &visitor) const override;

private:
  /// Integer value associated with the operand.
  int item_;
};

#endif /* _LEAF_NODE_H_ */
