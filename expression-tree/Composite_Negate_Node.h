/* -*- C++ -*- */
#ifndef _COMPOSITE_NEGATE_NODE_H_
#define _COMPOSITE_NEGATE_NODE_H_

#include "Composite_Unary_Node.h"

class Component_Node;
class Visitor;

/**
 * @class Composite_Negate_Node
 * @brief A composite node containing only a right child. 
 *        The meaning of this node is -right, eg -5, -7, etc.
 */
class Composite_Negate_Node : public Composite_Unary_Node
{
public:
  /// Ctor
  Composite_Negate_Node (Component_Node *right);

  /// Dtor
  virtual ~Composite_Negate_Node (void);

  /// Return the printable character stored in the node.
  virtual int item (void) const;

  /// Define the @a accept() operation used for the Visitor pattern.
  virtual void accept (Visitor &visitor) const;
};

#endif /* _COMPOSITE_NEGATE_NODE_H_ */
