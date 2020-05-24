/* -*- C++ -*- */
#ifndef _EVALUATION_VISITOR_H_
#define _EVALUATION_VISITOR_H_

#include "Visitor.h"
#include "LStack.h"

/// forward declarations of nodes
/// solves circular include problem

class Component_Node;
class Composite_Negate_Node;
class Composite_Add_Node;
class Composite_Subtract_Node;
class Composite_Divide_Node;
class Composite_Multiply_Node;

/**
 * @class Evaluation_Visitor
 * @brief This plays the role of a visitor for evaluating
 *        nodes in an expression tree that is being iterated in
 *        post-order fashion (and does not work correctly with any
 *        other iterator).
 */
class Evaluation_Visitor : public Visitor
{
public:
  /// Visit a @a Leaf_Node.
  virtual void visit (const Leaf_Node &node);

  /// Visit a @a Composite_Negate_Node.
  virtual void visit (const Composite_Negate_Node &node);

  /// Visit a @a Composite_Add_Node.
  virtual void visit (const Composite_Add_Node &node);

  /// Visit a @a Composite_Subtract_Node.
  virtual void visit (const Composite_Subtract_Node &node);

  /// Visit a @a Composite_Divide_Node.
  virtual void visit (const Composite_Divide_Node &node);

  /// Visit a @a Composite_Multiply_Node.
  virtual void visit (const Composite_Multiply_Node &node);

  /// Print the total of the evaluation.
  int total (void);

  /// Resets the evaluation to it can be reused.
  void reset (void);

private:
  /// Stack used for temporarily storing evaluations.
  LStack<int> stack_;
};  

#endif /* _VISITOR_H_ */
