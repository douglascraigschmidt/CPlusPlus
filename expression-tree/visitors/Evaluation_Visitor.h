/* -*- C++ -*- */
#ifndef _EVALUATION_VISITOR_H_
#define _EVALUATION_VISITOR_H_

#include <stack>
#include "visitors/Visitor.h"

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
  void visit (const Leaf_Node &node) override;

  /// Visit a @a Composite_Negate_Node.
  void visit (const Composite_Negate_Node &node) override;

  /// Visit a @a Composite_Add_Node.
  void visit (const Composite_Add_Node &node) override;

  /// Visit a @a Composite_Subtract_Node.
  void visit (const Composite_Subtract_Node &node) override;

  /// Visit a @a Composite_Divide_Node.
  void visit (const Composite_Divide_Node &node) override;

  /// Visit a @a Composite_Multiply_Node.
  void visit (const Composite_Multiply_Node &node) override;

  /// Print the total of the evaluation.
  int total ();

  /// Resets the evaluation to it can be reused.
  void reset ();

private:
  /// Stack used for temporarily storing evaluations.
  std::stack<int> stack_;
};  

#endif /* _VISITOR_H_ */
