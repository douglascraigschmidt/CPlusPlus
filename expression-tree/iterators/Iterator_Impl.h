/* -*- C++ -*- */
#ifndef _ITERATOR_IMPL_H
#define _ITERATOR_IMPL_H

#include <stack>
#include <queue>
#include <cstdlib>
#include <stdexcept>

// Solve circular include problem

template <typename T>
class Refcounter;
class Component_Node;
class Expression_Tree_Iterator;
class Expression_Tree;

/**
 * @class Iterator_Impl
 *
 * @brief Implementation of the Iterator pattern that is used to
 *        define the various iterations algorithms that can be
 *        performed to traverse the expression tree.
 * 
 *        Plays the role of the "implementor" base class in the Bridge
 *        pattern that is used as the basis for the subclasses that
 *        actually define the various iteration algorithms.
 *
 * @see   Expression_Tree_Level_Order_Iterator_Impl,
 *        Expression_Tree_In_Order_Iterator_Impl,
 *        Expression_Tree_Pre_Order_Iterator_Impl,
 *        Expression_Tree_Post_Order_Iterator_Impl,
 */
class Iterator_Impl
{
public:
  /// Construct an Iterator_Impl to iterate over a tree.
  explicit Iterator_Impl (const Expression_Tree &tree);

  /// Dtor.
  virtual ~Iterator_Impl ();

  /// Dereference operator returns a reference to the item contained
  /// at the current position.
  virtual Expression_Tree operator* () = 0;

  /// Returns a const reference to the item contained at the current
  /// position.
  virtual const Expression_Tree operator* () const = 0;

  /// Delegation operator returns a pointer to the item contained
  /// at the current position.
  virtual Expression_Tree *operator->() = 0;

  /// Delegation operator returns a const pointer to the item
  /// contained at the current position.
  virtual const Expression_Tree *operator-> () const = 0;

  /// Increment operator (used for both pre- and post-increment).
  virtual void operator++ () = 0;

  /// Equality operator.
  virtual bool operator== (const Iterator_Impl &rhs) const = 0;

  /// Nonequality operator.
  virtual bool operator!= (const Iterator_Impl &rhs) const = 0;

  /// Method for cloning an impl. Necessary for post increments.
  virtual Iterator_Impl *clone() = 0;

  /// = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

protected:
  /// The tree we are iterating over.
  const Expression_Tree &tree_;

  template<typename T> static bool is_equal_stack(T *lhs,
                                                  const Iterator_Impl &rhs);
};

/**
 * @class In_Order_Iterator_Impl
 *
 * @brief Iterates through an @a Expression_Tree in in-order.
 *
 *        Plays the role of the "implementor" class in the Bridge
 *        pattern that defines the in-order iteration algorithm.
 */
class In_Order_Iterator_Impl : public Iterator_Impl
{
  friend class Expression_Tree_Iterator;
  friend class Refcounter<Iterator_Impl>;
public:
  /// Construct an In_Order_Iterator_Impl. If end_iter is set to true,
  /// the iterator points to the end of the tree. Otherwise, the
  /// iterator starts with a free tree.
  explicit In_Order_Iterator_Impl (const Expression_Tree &tree,
                                   bool end_iter = false);

  /// Dtor.
  ~In_Order_Iterator_Impl () override;

  /// Dereference operator returns a reference to the item contained
  /// at the current position.
  Expression_Tree operator* () override;

  /// Returns a const reference to the item contained at the current
  /// position.
  const Expression_Tree operator* () const override;

  /// Increment operator (used for both pre- and post-increment).
  void operator++ () override;

  /// Delegation operator returns a pointer to the item contained
  /// at the current position.
  Expression_Tree *operator->() override;

  /// Delegation operator returns a const pointer to the item
  /// contained at the current position.
  const Expression_Tree *operator-> () const override;

  /// Equality operator.
  bool operator== (const Iterator_Impl &rhs) const override;

  /// Nonequality operator.
  bool operator!= (const Iterator_Impl &lhs) const override;

  /// Method for cloning an impl. Necessary for post increments.
  Iterator_Impl *clone () override;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

private:
  /// Our current position in the iteration.
  std::stack <Expression_Tree> stack_;

  friend class Iterator_Impl;
};

/**
 * @class Pre_Order_Iterator_Impl
 *
 * @brief Iterates through an @a Expression_Tree in level-order.
 *
 *        Plays the role of the "implementor" class in the Bridge
 *        pattern that defines the level-order iteration algorithm.
 */
class Pre_Order_Iterator_Impl : public Iterator_Impl
{
  friend class Expression_Tree_Iterator;
  friend class Refcounter<Iterator_Impl>;

public:
  /// Construct an Level_Order_Expression_Tree_Iterator. If end_iter
  /// is set to true, the iterator points to the end of the
  /// tree. Otherwise, the iterator starts with a free tree.
  explicit Pre_Order_Iterator_Impl (const Expression_Tree &tree,
                                    bool end_iter = false);

  /// Dtor.
  ~Pre_Order_Iterator_Impl () override;

  /// Dereference operator returns a reference to the item contained
  /// at the current position.
  Expression_Tree operator* () override;

  /// Returns a const reference to the item contained at the current
  /// position.
  const Expression_Tree operator* () const override;

  /// Increment operator (used for both pre- and post-increment).
  void operator++ () override;

  /// Delegation operator returns a pointer to the item contained
  /// at the current position.
  Expression_Tree *operator->() override;

  /// Delegation operator returns a const pointer to the item
  /// contained at the current position.
  const Expression_Tree *operator-> () const override;

  /// Equality operator.
  bool operator== (const Iterator_Impl &rhs) const override;

  /// Nonequality operator.
  bool operator!= (const Iterator_Impl &lhs) const override;

  /// Method for cloning an impl. Necessary for post increments.
  Iterator_Impl *clone () override;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

private:
  /// Our current position in the iteration.
  std::stack <Expression_Tree> stack_;

  friend class Iterator_Impl;
};

/**
 * @class Post_Order_Iterator_Impl
 *
 * @brief Iterates through an @a Expression_Tree in post-order.
 *
 *        Plays the role of the "implementor" class in the Bridge
 *        pattern that defines the post-order iteration algorithm.
 */
class Post_Order_Iterator_Impl : public Iterator_Impl
{
  friend class Expression_Tree_Iterator;
  friend class Refcounter<Iterator_Impl>;
public:

  /// Construct an Post_Order_Iterator_Impl. If end_iter is set
  /// to true, the iterator points to the end of the tree. Otherwise,
  /// the iterator starts with a free tree.
  explicit Post_Order_Iterator_Impl (const Expression_Tree &tree,
                                     bool end_iter = false);

  /// Dtor.
  ~Post_Order_Iterator_Impl () override;

  /// Dereference operator returns a reference to the item contained
  /// at the current position.
  Expression_Tree operator* () override;

  /// Returns a const reference to the item contained at the current
  /// position.
  const Expression_Tree operator* () const override;

  /// Increment operator (used for both pre- and post-increment).
  void operator++ () override;

  /// Delegation operator returns a pointer to the item contained
  /// at the current position.
  Expression_Tree *operator->() override;

  /// Delegation operator returns a const pointer to the item
  /// contained at the current position.
  const Expression_Tree *operator-> () const override;

  /// Equality operator.
  bool operator== (const Iterator_Impl &rhs) const override;

  /// Nonequality operator.
  bool operator!= (const Iterator_Impl &lhs) const override;

  /// Method for cloning an impl. Necessary for post increments.
  Iterator_Impl *clone () override;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

private:
  /// Our current position in the iteration.
  std::stack <Expression_Tree> stack_;

  friend class Iterator_Impl;
};

/**
 * @class Level_Order_Iter_Impl
 *
 * @brief Iterates through an @a Expression_Tree in level-order.
 *
 *        Plays the role of the "implementor" class in the Bridge
 *        pattern that defines the post-order iteration algorithm.
 */
class Level_Order_Iter_Impl : public Iterator_Impl
{
  friend class Expression_Tree_Iterator;
  friend class Refcounter<Iterator_Impl>;
public:

  /// Construct an Level_Order_Expression_Tree_Iterator. If end_iter
  /// is set to true, the iterator points to the end of the
  /// tree. Otherwise, the iterator starts with a free tree.
  explicit Level_Order_Iter_Impl (const Expression_Tree &tree,
                                  bool end_iter = false);

  /// Dtor.
  ~Level_Order_Iter_Impl () override;

  /// Dereference operator returns a reference to the item contained
  /// at the current position.
  Expression_Tree operator* () override;

  /// Returns a const reference to the item contained at the current
  /// position.
  const Expression_Tree operator* () const override;

  /// Increment operator (used for both pre- and post-increment).
  void operator++ () override;

  /// Delegation operator returns a pointer to the item contained
  /// at the current position.
  Expression_Tree *operator->() override;

  /// Delegation operator returns a const pointer to the item
  /// contained at the current position.
  const Expression_Tree *operator-> () const override;

  /// Equality operator.
  bool operator== (const Iterator_Impl &rhs) const override;

  /// Nonequality operator.
  bool operator!= (const Iterator_Impl &lhs) const override;

  /// Method for cloning an impl. Necessary for post increments.
  Iterator_Impl *clone () override;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef int value_type;
  typedef int *pointer;
  typedef int &reference;
  typedef int difference_type;

private:
  /// Our current position in the iteration.
  std::queue <Expression_Tree> queue_;

  friend class Iter_Impl;
};

#endif /* _ITERATOR_IMPL_H */
