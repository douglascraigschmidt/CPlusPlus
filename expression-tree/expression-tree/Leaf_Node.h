/* -*- C++ -*- */
#ifndef _LEAF_NODE_H_
#define _LEAF_NODE_H_

#include <string>
#include "Component_Node.h"

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
  Leaf_Node (int item);

  /// Ctor.
  Leaf_Node (const std::string &item);

  /// Ctor.
  Leaf_Node (const char *item);

  /// Dtor.
  virtual ~Leaf_Node (void);

  /// Return the item stored in the node.
  virtual int item (void) const;

  /// Define the @a accept() operation used for the Visitor pattern.
  virtual void accept (Visitor &visitor) const; 

private:
  /// Integer value associated with the operand.
  int item_;
};

#endif /* _LEAF_NODE_H_ */
