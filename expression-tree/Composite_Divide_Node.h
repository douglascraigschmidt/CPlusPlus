/* -*- C++ -*- */
#ifndef _COMPOSITE_DIVIDE_NODE_H_
#define _COMPOSITE_DIVIDE_NODE_H

class Component_Node;
class Composite_Binary_Node;
class Visitor;

/**
 * @class Composite_Divide_Node
 * @brief A composite node containing left and right
 *        children. The meaning of this node is left / right.
 */
class Composite_Divide_Node : public Composite_Binary_Node
{
public:
  /// Ctor
  Composite_Divide_Node (Component_Node *left, 
                         Component_Node *right);

  /// Dtor
  virtual ~Composite_Divide_Node (void);

  /// Return the printable character stored in the node.
  virtual int item (void) const;

  /// Define the @a accept() operation used for the Visitor pattern.
  virtual void accept (Visitor &visitor) const;
};

#endif /* _COMPOSITE_DIVIDE_NODE_H_ */
