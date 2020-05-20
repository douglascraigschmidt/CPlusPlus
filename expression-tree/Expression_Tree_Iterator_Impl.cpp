/* -*- C++ -*- */
#ifndef _TREE_ITERATOR_IMPL_CPP
#define _TREE_ITERATOR_IMPL_CPP

#include "Expression_Tree.h"
#include "Expression_Tree_Iterator_Impl.h"
#include "Component_Node.h"

const size_t LQUEUE_SIZE = 40;

// Constructor for Expression_Tree_Iterator_Impl that takes a tree
// to iterate over

Expression_Tree_Iterator_Impl::Expression_Tree_Iterator_Impl (const Expression_Tree &tree)
  : tree_ (tree)
{
}

// Destructor

Expression_Tree_Iterator_Impl::~Expression_Tree_Iterator_Impl (void)
{
}

/// Construct an In_Order_Expression_Tree_Iterator_Impl. If end_iter is set to true,
/// the iterator points to the end of the tree

In_Order_Expression_Tree_Iterator_Impl::In_Order_Expression_Tree_Iterator_Impl (const Expression_Tree &tree,
                                                                                bool end_iter)
  : Expression_Tree_Iterator_Impl (tree),
    stack_ ()
{
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !this->tree_.is_null ())
    {
      stack_.push (const_cast <Expression_Tree &> (tree));

      // start at the smallest element (left-most)
      while (!stack_.top ().left ().is_null ())
        stack_.push (stack_.top ().left ());
    }
}

/// destructor - nothing to do

In_Order_Expression_Tree_Iterator_Impl::~In_Order_Expression_Tree_Iterator_Impl (void)
{
}

/// Returns the Node that the iterator is pointing to (non-const version)
 
Expression_Tree 
In_Order_Expression_Tree_Iterator_Impl::operator* (void)
{
  return stack_.top ();
}

/// Returns the Node that the iterator is pointing to (const version)
 
const Expression_Tree 
In_Order_Expression_Tree_Iterator_Impl::operator* (void) const
{
  return stack_.top ();
}

/// moves the iterator to the next node (pre-increment)
 
void
In_Order_Expression_Tree_Iterator_Impl::operator++ (void)
{
  // we know that at this point there is no left () of top ()
  // because we would have already visited it.

  if (!stack_.is_empty ())
    {
      // if we have nodes greater than ourselves
      if (!stack_.top ().right ().is_null ())
        {
          // push the right child node onto the stack
          // and pop the old parent (it's been visited now)
          stack_.push (stack_.pop ().right ());

          // keep pushing until we get to the left most child
          while (!stack_.top ().left ().is_null ())
            stack_.push (stack_.top ().left ());
        }
      else
        stack_.pop ();
    }
}

/// checks two iterators for equality
 
bool 
In_Order_Expression_Tree_Iterator_Impl::operator== (const Expression_Tree_Iterator_Impl &rhs) const
{
  const In_Order_Expression_Tree_Iterator_Impl * in_order_rhs = dynamic_cast
    <const In_Order_Expression_Tree_Iterator_Impl *> (&rhs);

  // if the rhs was not a level_order iterator then we've already
  // discovered the relation is false.

  if (in_order_rhs)
    {
      // Check if the container we are iterating over has the same
      // root node and that the size of the queues are equal. The
      // latter doesn't truly determine equality. However, this is an
      // easy check for determining most inequalities and it allows us
      // to assume the queue at least has a front node (coupled with
      // the is_empty () function later).

      Expression_Tree &t1 = const_cast <Expression_Tree &> (tree_);
      Expression_Tree &t2 = const_cast <Expression_Tree &> (in_order_rhs->tree_);

      if (t1.get_root () == t2.get_root () 
          && stack_.size () == in_order_rhs->stack_.size ())
        {
          // Check for both being is_empty (special condition).
          if (stack_.is_empty () && in_order_rhs->stack_.is_empty ())
            return true;

          // check the front's node pointer. If the node pointers are
          // equal, then both iterators are pointing to the same
          // position in the tree.

          if (stack_.top ().get_root () == in_order_rhs->stack_.top ().get_root ())
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
In_Order_Expression_Tree_Iterator_Impl::operator!= (const Expression_Tree_Iterator_Impl &rhs) const
{
  return ! (*this == rhs);
}

/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
 
Expression_Tree_Iterator_Impl * 
In_Order_Expression_Tree_Iterator_Impl::clone (void)
{
  return new In_Order_Expression_Tree_Iterator_Impl (*this);
}

/// Construct an Pre_Order_Expression_Tree_Iterator. If end_iter is set to true,
/// the iterator points to the end of the tree

Pre_Order_Expression_Tree_Iterator_Impl::Pre_Order_Expression_Tree_Iterator_Impl (const Expression_Tree &tree,
                                                            bool end_iter)
  : Expression_Tree_Iterator_Impl (tree), 
    stack_ ()
{
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !this->tree_.is_null ())
    stack_.push (const_cast <Expression_Tree &> (tree));
}

/// destructor - nothing to do

Pre_Order_Expression_Tree_Iterator_Impl::~Pre_Order_Expression_Tree_Iterator_Impl (void)
{

}

/// Returns the Node that the iterator is pointing to (non-const version)
 
Expression_Tree 
Pre_Order_Expression_Tree_Iterator_Impl::operator* (void)
{
  return stack_.top ();
}

/// Returns the Node that the iterator is pointing to (const version)
 
const Expression_Tree 
Pre_Order_Expression_Tree_Iterator_Impl::operator* (void) const
{
  return stack_.top ();
}

/// moves the iterator to the next node (pre-increment)
 
void
Pre_Order_Expression_Tree_Iterator_Impl::operator++ (void)
{
  // we know that at this point there is no left () of top ()
  // because we would have already visited it.

  if (!stack_.is_empty ())
    {
      // we need to pop the node off the stack before pushing the
      // children, or else we'll revisit this node later

      Expression_Tree current = stack_.pop ();

      // note the order here: right first, then left. Since this is
      // LIFO, this results in the left child being the first
      // evaluated, which fits into the Pre-order traversal strategy

      if (!current.right ().is_null ())
        stack_.push (current.right ());
      if (!current.left ().is_null ())
        stack_.push (current.left ());
    }
}

/// checks two iterators for equality
 
bool 
Pre_Order_Expression_Tree_Iterator_Impl::operator== (const Expression_Tree_Iterator_Impl &rhs) const
{
  const Pre_Order_Expression_Tree_Iterator_Impl *pre_order_rhs = dynamic_cast
    <const Pre_Order_Expression_Tree_Iterator_Impl *> (&rhs);

  // if the rhs was not a level_order iterator
  // then we've already discovered the relation is false

  if (pre_order_rhs)
    {
      // check if the container we are iterating over has the same
      // root node and that the size of the queues are equal. The
      // latter doesn't truly determine equality. However, this is an
      // easy check for determining most inequalities and it allows us
      // to assume the queue at least has a front node (coupled with
      // the is_empty () function later).

      Expression_Tree &t1 = const_cast <Expression_Tree &> (tree_);
      Expression_Tree &t2 = const_cast <Expression_Tree &> (pre_order_rhs->tree_);

      if (t1.get_root () == t2.get_root () 
          && stack_.size () == pre_order_rhs->stack_.size ())
        {
          // check for both being is_empty (special condition)
          if (stack_.is_empty () && pre_order_rhs->stack_.is_empty ())
            return true;

          // check the front's node pointer. If the node pointers
          // are equal, then both iterators are pointing to the same
          // position in the tree.

          if (stack_.top ().get_root () == pre_order_rhs->stack_.top ().get_root ())
            return true;
        }
    }

  // either we were trying to compare a non-level order iterator or
  // we were comparing two level order iterators that were obviously
  // at different points in the tree (their queue sizes were different)

  return false;
}

/// checks two iterators for inequality
 
bool 
Pre_Order_Expression_Tree_Iterator_Impl::operator!= (const Expression_Tree_Iterator_Impl &rhs) const
{
  return ! (*this == rhs);
}


/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
 
Expression_Tree_Iterator_Impl * 
Pre_Order_Expression_Tree_Iterator_Impl::clone (void)
{
  return new Pre_Order_Expression_Tree_Iterator_Impl (*this);
}

/// Construct an Post_Order_Expression_Tree_Iterator. If end_iter is set to true,
/// the iterator points to the end of the tree

Post_Order_Expression_Tree_Iterator_Impl::Post_Order_Expression_Tree_Iterator_Impl (const Expression_Tree &tree,
                                                              bool end_iter)
  : Expression_Tree_Iterator_Impl (tree), 
    stack_ ()
{
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !this->tree_.is_null ())
    {
      Expression_Tree current = const_cast <Expression_Tree &> (tree);
      stack_.push (current);

// the commented code does not work on unary operator nodes with no left child, but 
// a right child - or at least, there is a certain depth that this will not go down

      while (!current.is_null ())
        {
          if (!current.right ().is_null ())
            stack_.push (current.right ());
          if (!current.left ().is_null ())
            {
              // if there was a left, then update current
              // this is the case for all non-negations
              stack_.push (current.left ());
              current = current.left ();
            }
          else
            // if there was not a left, then current = current->right_
            // this handles cases of unary nodes, like negations
            current = current.right ();
        }
    }
}

/// destructor - nothing to do

Post_Order_Expression_Tree_Iterator_Impl::~Post_Order_Expression_Tree_Iterator_Impl (void)
{
}

/// Returns the Node that the iterator is pointing to (non-const version)
 
Expression_Tree 
Post_Order_Expression_Tree_Iterator_Impl::operator* (void)
{
  return stack_.top ();
}

/// Returns the Node that the iterator is pointing to (const version)
 
const Expression_Tree 
Post_Order_Expression_Tree_Iterator_Impl::operator* (void) const
{
  return stack_.top ();
}

/// moves the iterator to the next node (pre-increment)
 
void
Post_Order_Expression_Tree_Iterator_Impl::operator++ (void)
{
  // we know that at this point there is no left () of top ()
  // because we would have already visited it.

  if (!stack_.is_empty ())
    {
      // we need to pop the node off the stack before pushing the
      // children, or else we'll revisit this node later

      Expression_Tree current = stack_.pop ();

      // This is where stuff gets a little confusing.

      if (!stack_.is_empty () 
          && stack_.top ().left ().get_root () != current.get_root ()
          && stack_.top ().right ().get_root () != current.get_root () )
        {
          current = stack_.top ();

          while (!current.is_null ())
            {
              if (!current.right ().is_null ())
                stack_.push (current.right ());
              if (!current.left ().is_null ())
                {
                  // if there was a left, then update current
                  // this is the case for all non-negations
                  stack_.push (current.left ());
                  current = current.left ();
                }
              else
                {
                  // if there was not a left, then current = current->right_
                  // this handles cases of unary nodes, like negations
                  current = current.right ();
                }
            }
        }
    }
}

/// checks two iterators for equality
 
bool 
Post_Order_Expression_Tree_Iterator_Impl::operator== (const Expression_Tree_Iterator_Impl &rhs) const
{
  const Post_Order_Expression_Tree_Iterator_Impl * post_order_rhs = dynamic_cast
    <const Post_Order_Expression_Tree_Iterator_Impl *> (&rhs);

  // if the rhs was not a level_order iterator
  // then we've already discovered the relation is false

  if (post_order_rhs)
    {
      // check if the container we are iterating over has the same
      // root node and that the size of the queues are equal. The
      // latter doesn't truly determine equality. However, this is an
      // easy check for determining most inequalities and it allows us
      // to assume the queue at least has a front node (coupled with
      // the is_empty () function later).

      Expression_Tree &t1 = const_cast <Expression_Tree &> (tree_);
      Expression_Tree &t2 = const_cast <Expression_Tree &> (post_order_rhs->tree_);

      if (t1.get_root () == t2.get_root () 
          && stack_.size () == post_order_rhs->stack_.size ())
        {
          // check for both being is_empty (special condition)
          if (stack_.is_empty () && post_order_rhs->stack_.is_empty ())
            return true;

          // check the front's node pointer. If the node pointers are
          // equal, then both iterators are pointing to the same
          // position in the tree.

          if (stack_.top ().get_root () == post_order_rhs->stack_.top ().get_root ())
            return true;
        }
    }

  // either we were trying to compare a non-level order iterator or
  // we were comparing two level order iterators that were obviously
  // at different points in the tree (their queue sizes were different)

  return false;
}

/// checks two iterators for inequality
 
bool 
Post_Order_Expression_Tree_Iterator_Impl::operator!= (const Expression_Tree_Iterator_Impl &rhs) const
{
  return ! (*this == rhs);
}

/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
 
Expression_Tree_Iterator_Impl * 
Post_Order_Expression_Tree_Iterator_Impl::clone (void)
{
  return new Post_Order_Expression_Tree_Iterator_Impl (*this);
}

/// Construct an Level_Order_Expression_Tree_Iterator. If end_iter is set to
/// true, the iterator points to the end of the tree

Level_Order_Expression_Tree_Iterator_Impl::Level_Order_Expression_Tree_Iterator_Impl (const Expression_Tree &tree,
                                                                                      bool end_iter)
  : Expression_Tree_Iterator_Impl (tree), 
    queue_ (LQUEUE_SIZE)
{
  // if the caller doesn't want an end iterator, insert the root tree
  // into the queue.
  if (!end_iter && !this->tree_.is_null ())
    queue_.enqueue (const_cast <Expression_Tree &> (tree));
}

/// destructor - nothing to do

Level_Order_Expression_Tree_Iterator_Impl::~Level_Order_Expression_Tree_Iterator_Impl (void)
{
}

/// Returns the Node that the iterator is pointing to (non-const version)
 
Expression_Tree 
Level_Order_Expression_Tree_Iterator_Impl::operator* (void)
{
  return queue_.front ();
}

/// Returns the Node that the iterator is pointing to (const version)
 
const Expression_Tree 
Level_Order_Expression_Tree_Iterator_Impl::operator* (void) const
{
  return queue_.front ();
}

/// moves the iterator to the next node (pre-increment)
 
void
Level_Order_Expression_Tree_Iterator_Impl::operator++ (void) 
{
  if (!queue_.is_empty ())
    {
      // If the queue is not empty, dequeue an element
      Expression_Tree root = queue_.dequeue ();

      if (!root.is_null ())
        {
          // If the element wasn't null, enqueue its children
          if (!root.left ().is_null ())
            queue_.enqueue (root.left ());
          if (!root.right ().is_null ())
            queue_.enqueue (root.right ());
        }
    }
}

/// checks two iterators for equality
 
bool 
Level_Order_Expression_Tree_Iterator_Impl::operator== (const Expression_Tree_Iterator_Impl &rhs) const
{
  const Level_Order_Expression_Tree_Iterator_Impl * level_order_rhs = dynamic_cast
    <const Level_Order_Expression_Tree_Iterator_Impl *> (&rhs);

  // if the rhs was not a level_order iterator then we've already
  // discovered the relation is false.

  if (level_order_rhs)
    {
      // check if the container we are iterating over has the same
      // root node and that the size of the queues are equal. The
      // latter doesn't truly determine equality. However, this is an
      // easy check for determining most inequalities and it allows us
      // to assume the queue at least has a front node (coupled with
      // the is_empty () function later).

      Expression_Tree &t1 = const_cast <Expression_Tree &> (tree_);
      Expression_Tree &t2 = const_cast <Expression_Tree &> (level_order_rhs->tree_);

      if (t1.get_root () == t2.get_root () 
          && queue_.size () == level_order_rhs->queue_.size ())
        {
          // check for both being is_empty (special condition)
          if (queue_.is_empty () && level_order_rhs->queue_.is_empty ())
            return true;

          // check the front's node pointer. If the node pointers
          // are equal, then both iterators are pointing to the same
          // position in the tree.

          if (queue_.front ().get_root () == level_order_rhs->queue_.front ().get_root ())
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
Level_Order_Expression_Tree_Iterator_Impl::operator!= (const Expression_Tree_Iterator_Impl &rhs) const
{
  return !(*this == rhs);
}

/// Method for cloning an impl. Necessary for post increments (bridge)
/// @see Expression_Tree_Iterator
 
Expression_Tree_Iterator_Impl * 
Level_Order_Expression_Tree_Iterator_Impl::clone (void)
{
  return new Level_Order_Expression_Tree_Iterator_Impl (*this);
}

#endif /* _TREE_ITERATOR_IMPL_CPP */

