/* -*- C++ -*- */
#ifndef _VISITOR_H_
#define _VISITOR_H_

class Leaf_Node;
class Composite_Negate_Node;
class Composite_Add_Node;
class Composite_Subtract_Node;
class Composite_Divide_Node;
class Composite_Multiply_Node;

/**
 * @class Visitor
 * @brief Abstract base class for all visitors to all classes that derive
 *        from @a Component_Node.
 *
 *        This class plays the role of the "visitor" in the Visitor
 *        pattern. 
 */
class Visitor
{
public:
  /// Visit a @a Leaf_Node.
  virtual void visit (const Leaf_Node &node) = 0;

  /// Visit a @a Composite_Negate_Node.
  virtual void visit (const Composite_Negate_Node &node) = 0;

  /// Visit a @a Composite_Add_Node.
  virtual void visit (const Composite_Add_Node &node) = 0;

  /// Visit a @a Composite_Subtract_Node.
  virtual void visit (const Composite_Subtract_Node &node) = 0;

  /// Visit a @a Composite_Divide_Node.
  virtual void visit (const Composite_Divide_Node &node) = 0;

  /// Visit a @a Composite_Multiply_Node.
  virtual void visit (const Composite_Multiply_Node &node) = 0;

  /// No-op destructor to hold things together.
  virtual ~Visitor () = 0;
};

#endif /* _VISITOR_H_ */
