/* -*- C++ -*- */
#ifndef _COMPOSITE_MULTIPLY_NODE_H
#define _COMPOSITE_MULTIPLY_NODE_H

class Component_Node;
class Composite_Binary_Node;
class Visitor;

/**
 * @class Composite_Multiply_Node
 * @brief A composite node containing left and right
 *        children. The meaning of this node is left * right
 */
class Composite_Multiply_Node : public Composite_Binary_Node
{
public:
  /// Ctor
  Composite_Multiply_Node (Component_Node *left,
                           Component_Node *right);

  /// Dtor
  virtual ~Composite_Multiply_Node (void);

  /// Return the printable character stored in the node.
  virtual int item (void) const;

  /// Define the @a accept() operation used for the Visitor pattern.
  virtual void accept (Visitor &visitor) const;
};

#endif /* _COMPOSITE_MULTIPLY_NODE_H */
