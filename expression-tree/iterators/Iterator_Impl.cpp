/* -*- C++ -*- */
#ifndef _TREE_ITERATOR_IMPL_CPP
#define _TREE_ITERATOR_IMPL_CPP

#include "trees/Expression_Tree.h"
#include "iterators/Iterator_Impl.h"
#include "composites/Component_Node.h"

// Constructor for Iterator_Impl that takes a tree to iterate over.
Iterator_Impl::Iterator_Impl (const Expression_Tree &tree)
  : tree_ (tree) {
}

// Destructor
Iterator_Impl::~Iterator_Impl () = default;

template<typename T> bool
Iterator_Impl::is_equal_stack(T *lhs, const Iterator_Impl &rhs) {
  // if the rhs was not an iterator for type T then we've already
  // discovered the relation is false.
  if (auto rhs_downcast = dynamic_cast <decltype(lhs)> (&rhs)) {
      // Check if the container we are iterating over has the same
      // root node and that the size of the queues are equal. The
      // latter doesn't truly determine equality. However, this is an
      // easy check for determining most inequalities and it allows us
      // to assume the queue at least has a front node (coupled with
      // the is_empty () function later).
      auto &t1 = lhs->tree_, &t2 = rhs_downcast->tree_;
      auto &s1 = lhs->stack_, &s2 = rhs_downcast->stack_;

      if (t1.get_root () == t2.get_root () 
          && s1.size () == s2.size ()) {
          // Check for both being is_empty (special condition).
          if (s1.empty () && s2.empty ())
            return true;

          // check the front's node pointer. If the node pointers are
          // equal, then both iterators are pointing to the same
          // position in the tree.
          if (s1.top ().get_root () == s2.top ().get_root ())
            return true;
        }
    }

  // either we were trying to compare a non-level order iterator or we
  // were comparing two level order iterators that were obviously at
  // different points in the tree (their queue sizes were different)

  return false;
}

/// Construct an In_Order_Iterator_Impl. If end_iter is set to true,
/// the iterator points to the end of the tree
In_Order_Iterator_Impl::In_Order_Iterator_Impl (const Expression_Tree &tree,
                                                bool end_iter)
  : Iterator_Impl (tree),
    stack_ () {
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !tree_.is_null ()) {
    stack_.push (tree);

    // start at the smallest element (left-most)
    while (!stack_.top ().left ().is_null ())
      stack_.push (stack_.top ().left ());
  }
}

/// destructor - nothing to do

In_Order_Iterator_Impl::~In_Order_Iterator_Impl () = default;

/// Returns the Node that the iterator is pointing to (non-const version)
Expression_Tree 
In_Order_Iterator_Impl::operator* () {
  return stack_.top ();
}

/// Returns the Node that the iterator is pointing to (const version)
const Expression_Tree 
In_Order_Iterator_Impl::operator* () const {
  return stack_.top ();
}

/// moves the iterator to the next node (pre-increment)
void
In_Order_Iterator_Impl::operator++ () {
  // we know that at this point there is no left () of top () because
  // we would have already visited it.

  if (!stack_.empty ()) {
    // if we have nodes greater than ourselves
    if (!stack_.top ().right ().is_null ()) {
      auto right_child = stack_.top().right ();
      // Push the right child node onto the stack and pop the old
      // parent (it's been visited now).
      stack_.pop();
      stack_.push (right_child);

      // keep pushing until we get to the left most child
      while (!stack_.top ().left ().is_null ())
        stack_.push (stack_.top ().left ());
    } else
      stack_.pop ();
  }
}

/// Delegation operator.
Expression_Tree *
In_Order_Iterator_Impl::operator->() {
  return &stack_.top ();
}

/// Delegation operator.
const Expression_Tree *
In_Order_Iterator_Impl::operator-> () const {
  return &stack_.top ();
}

/// checks two iterators for equality
bool 
In_Order_Iterator_Impl::operator== (const Iterator_Impl &rhs) const {
  return Iterator_Impl::is_equal_stack(this, rhs);
}

/// checks two iterators for inequality
bool 
In_Order_Iterator_Impl::operator!= (const Iterator_Impl &rhs) const {
  return !(*this == rhs);
}

/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
Iterator_Impl *
In_Order_Iterator_Impl::clone () {
  return new In_Order_Iterator_Impl (*this);
}

/// Construct an Pre_Order_Expression_Tree_Iterator. If end_iter is
/// set to true, the iterator points to the end of the tree
Pre_Order_Iterator_Impl::Pre_Order_Iterator_Impl (const Expression_Tree &tree,
                                                  bool end_iter)
  : Iterator_Impl (tree),
    stack_ () {
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !tree_.is_null ())
    stack_.push (tree);
}

/// destructor - nothing to do

Pre_Order_Iterator_Impl::~Pre_Order_Iterator_Impl () = default;

/// Returns the Node that the iterator is pointing to (non-const version)
Expression_Tree 
Pre_Order_Iterator_Impl::operator* () {
  return stack_.top ();
}

/// Returns the Node that the iterator is pointing to (const version)
const Expression_Tree 
Pre_Order_Iterator_Impl::operator* () const {
  return stack_.top ();
}

/// moves the iterator to the next node (pre-increment)
void
Pre_Order_Iterator_Impl::operator++ () {
  // we know that at this point there is no left () of top () because
  // we would have already visited it.

  if (!stack_.empty ()) {
    // we need to pop the node off the stack before pushing the
    // children, or else we'll revisit this node later

    Expression_Tree current = stack_.top ();
    stack_.pop();

    // note the order here: right first, then left. Since this is
    // LIFO, this results in the left child being the first
    // evaluated, which fits into the Pre-order traversal strategy

    if (!current.right ().is_null ())
      stack_.push (current.right ());
    if (!current.left ().is_null ())
      stack_.push (current.left ());
  }
}

/// Delegation operator.
Expression_Tree *
Pre_Order_Iterator_Impl::operator->() {
  return &stack_.top ();
}

/// Delegation operator.
const Expression_Tree *
Pre_Order_Iterator_Impl::operator-> () const {
  return &stack_.top ();
}

/// checks two iterators for equality
bool 
Pre_Order_Iterator_Impl::operator== (const Iterator_Impl &rhs) const {
  return Iterator_Impl::is_equal_stack(this, rhs);
}

/// checks two iterators for inequality
bool 
Pre_Order_Iterator_Impl::operator!= (const Iterator_Impl &rhs) const {
  return !(*this == rhs);
}


/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
Iterator_Impl *
Pre_Order_Iterator_Impl::clone () {
  return new Pre_Order_Iterator_Impl (*this);
}

/// Construct an Post_Order_Expression_Tree_Iterator. If end_iter is
/// set to true, the iterator points to the end of the tree
Post_Order_Iterator_Impl::Post_Order_Iterator_Impl (const Expression_Tree &tree,
                                                    bool end_iter)
  : Iterator_Impl (tree),
    stack_ () {
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !tree_.is_null ()) {
    Expression_Tree current = const_cast <Expression_Tree &> (tree);
    stack_.push (current);

    // the commented code does not work on unary operator nodes with no left child, but 
    // a right child - or at least, there is a certain depth that this will not go down

    while (!current.is_null ()) {
      if (!current.right ().is_null ())
        stack_.push (current.right ());
      if (!current.left ().is_null ()) {
        // if there was a left, then update current
        // this is the case for all non-negations
        stack_.push (current.left ());
        current = current.left ();
      } else
        // if there was not a left, then current = current->right_
        // this handles cases of unary nodes, like negations
        current = current.right ();
    }
  }
}

/// destructor - nothing to do
Post_Order_Iterator_Impl::~Post_Order_Iterator_Impl () = default;

/// Returns the Node that the iterator is pointing to (non-const version)
Expression_Tree 
Post_Order_Iterator_Impl::operator* () {
  return stack_.top ();
}

/// Returns the Node that the iterator is pointing to (const version)
const Expression_Tree 
Post_Order_Iterator_Impl::operator* () const {
  return stack_.top ();
}

/// moves the iterator to the next node (pre-increment)
void
Post_Order_Iterator_Impl::operator++ () {
  // we know that at this point there is no left () of top ()
  // because we would have already visited it.

  if (!stack_.empty ()) {
    // we need to pop the node off the stack before pushing the
    // children, or else we'll revisit this node later

    Expression_Tree current = stack_.top ();
    stack_.pop();

    // This is where stuff gets a little confusing.

    if (!stack_.empty ()
        && stack_.top ().left ().get_root () != current.get_root ()
        && stack_.top ().right ().get_root () != current.get_root ()) {
      current = stack_.top ();

      while (!current.is_null ()) {
        if (!current.right ().is_null ())
          stack_.push (current.right ());
        if (!current.left ().is_null ()) {
          // if there was a left, then update current
          // this is the case for all non-negations
          stack_.push (current.left ());
          current = current.left ();
        } else 
          // if there was not a left, then current = current->right_
          // this handles cases of unary nodes, like negations
          current = current.right ();
      }
    }
  }
}

/// Delegation operator.
Expression_Tree *
Post_Order_Iterator_Impl::operator->() {
  return &stack_.top ();
}

/// Delegation operator.
const Expression_Tree *
Post_Order_Iterator_Impl::operator-> () const {
  return &stack_.top ();
}

/// checks two iterators for equality
bool 
Post_Order_Iterator_Impl::operator== (const Iterator_Impl &rhs) const {
  return Iterator_Impl::is_equal_stack(this, rhs);}

/// checks two iterators for inequality
bool 
Post_Order_Iterator_Impl::operator!= (const Iterator_Impl &rhs) const {
  return ! (*this == rhs);
}

/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
Iterator_Impl *
Post_Order_Iterator_Impl::clone () {
  return new Post_Order_Iterator_Impl (*this);
}

/// Construct an Level_Order_Expression_Tree_Iterator. If end_iter is set to
/// true, the iterator points to the end of the tree
Level_Order_Iter_Impl::Level_Order_Iter_Impl (const Expression_Tree &tree,
                                              bool end_iter)
  : Iterator_Impl (tree),
    queue_ () {
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !tree_.is_null ())
    queue_.push (tree);
}

/// destructor - nothing to do

Level_Order_Iter_Impl::~Level_Order_Iter_Impl () = default;

/// Returns the Node that the iterator is pointing to (non-const version)
Expression_Tree 
Level_Order_Iter_Impl::operator* () {
  return queue_.front ();
}

/// Returns the Node that the iterator is pointing to (const version)
const Expression_Tree 
Level_Order_Iter_Impl::operator* () const {
  return queue_.front ();
}

/// moves the iterator to the next node (pre-increment)
void
Level_Order_Iter_Impl::operator++ () {
  if (!queue_.empty ()) {
    // If the queue is not empty, dequeue an element
    Expression_Tree root = queue_.front ();
    queue_.pop();

    if (!root.is_null ()) {
      // If the element wasn't null, enqueue its children
      if (!root.left ().is_null ())
        queue_.push (root.left ());
      if (!root.right ().is_null ())
        queue_.push (root.right ());
    }
  }
}

/// Delegation operator.
Expression_Tree *
Level_Order_Iter_Impl::operator->() {
  return &queue_.front ();
}

/// Delegation operator.
const Expression_Tree *
Level_Order_Iter_Impl::operator-> () const {
  return &queue_.front ();
}

/// checks two iterators for equality
bool 
Level_Order_Iter_Impl::operator== (const Iterator_Impl &rhs) const {
  // if the rhs was not a level_order iterator then we've already
  // discovered the relation is false.
  if (auto level_order_rhs = dynamic_cast<decltype(this)> (&rhs)) {
    // check if the container we are iterating over has the same root
    // node and that the size of the queues are equal. The latter
    // doesn't truly determine equality. However, this is an easy
    // check for determining most inequalities and it allows us to
    // assume the queue at least has a front node (coupled with the
    // is_empty () function later).

    auto &t1 = tree_, &t2 = level_order_rhs->tree_;
    auto &q1 = queue_, &q2 = level_order_rhs->queue_;
    if (t1.get_root () == t2.get_root () 
        && q1.size () == q2.size ()) {
      // check for both being is_empty (special condition)
      if (q1.empty () && q2.empty ())
        return true;

      // check the front's node pointer. If the node pointers
      // are equal, then both iterators are pointing to the same
      // position in the tree.
      if (q1.front ().get_root () == q2.front ().get_root ())
        return true;
    }
  }

  // either we were trying to compare a non-level order iterator or we
  // were comparing two level order iterators that were obviously at
  // different points in the tree (their queue sizes were different)
  return false;
}

/// checks two iterators for inequality
bool 
Level_Order_Iter_Impl::operator!= (const Iterator_Impl &rhs) const {
  return !(*this == rhs);
}

/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
Iterator_Impl *
Level_Order_Iter_Impl::clone () {
  return new Level_Order_Iter_Impl (*this);
}

#endif /* _TREE_ITERATOR_IMPL_CPP */

