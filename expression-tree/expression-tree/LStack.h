/* -*- C++ -*- */
#ifndef _LSTACK_H_
#define _LSTACK_H_

// This header defines "size_t"
#include <stdlib.h>
#include <stdexcept>

// Solve circular include problem via forward decls.
template <typename T>
class LStack_Node;

template <typename T>
class LStack_Iterator;

template <typename T>
class LStack_Const_Iterator;

/**
 * @class LStack
 * @brief Defines a generic "last-in/first-out" (LIFO) Abstract Data
 *        Type (ADT) using a stack that's implemented as a linked list.
 */
template <class T> 
class LStack
{
  friend class LStack_Iterator<T>;
  friend class LStack_Const_Iterator<T>;
public:
  // Define a "trait"
  typedef T value_type;

  /**
   * @class Underflow
   * @brief Exception thrown by methods in this class when an
   *        underflow condition occurs. 
   */
  class Underflow {};

  /**
   * @class Overflow.
   * @brief Exception thrown by methods in this class when an overflow
   *        condition occurs.  
   */
  class Overflow {};

  /// Constructor.
  LStack (size_t size_hint = 0);

  /// Copy constructor.
  LStack (const LStack<T> &rhs);

  /// Assignment operator.
  LStack<T> &operator = (const LStack<T> &rhs);

  /// Perform actions needed when stack goes out of scope. 
  ~LStack (void);

  /// Place a @a new_item at the tail of the stack.  Throws the @a
  /// Overflow exception if the stack is full, e.g., if memory is
  /// exhausted.
  void push (const T &new_item);

  /// Remove and return the front item on the stack.  Throws the @a
  /// Underflow exception if the stack is empty.
  T pop (void);

  /// Returns the front stack item without removing it.  Throws the @a
  /// Underflow exception if the stack is empty.
  T top (void) const;

  /// Returns 1 if the stack is empty, otherwise returns 0. 
  bool is_empty (void) const;

  /// Returns 1 if the stack is full, otherwise returns 0. 
  bool is_full (void) const;

  /// Returns the current number of elements in the stack.
  size_t size (void) const;

  /// Compare this stack with @a rhs for equality.  Returns true if
  /// the size's of the two stacks are equal and all the elements from
  /// 0 .. size() are equal, else false.
  bool operator== (const LStack<T> &rhs) const;

  // Compare this stack with @a rhs for inequality such that @a
  // *this!=s is always the complement of the boolean return value of
  // @a *this==s.
  bool operator!= (const LStack<T> &s) const;

  /// Delete all the nodes in the LStack.
  void erase (void);

  typedef LStack_Iterator<T> iterator;
  typedef LStack_Const_Iterator<T> const_iterator;

  /// Get an iterator that points to the beginning of the stack.
  iterator begin (void);

  /// Get a const iterator that points to the beginning of the stack.
  const_iterator begin (void) const;

  /// Get an iterator that points to the end of the stack.
  iterator end (void);

  /// Get a const iterator that points to the end of the stack.
  const_iterator end (void) const;

protected:
  /// Remove the front item on the stack.  does not throw exceptions.
  void pop_i (void);

  /// Copy a linked list of nodes.  This can throw a @a std::bad_alloc
  /// exception.
  void copy_list (const LStack<T> &rhs);

  /// Delete a linked list of nodes.
  void delete_list (void);

private:
  /// We only need to keep a single pointer for the circular linked
  /// list.  This points to the tail of the stack.  Since the list is
  /// circular, the head of the stack is always @a head_->next_.
  LStack_Node<T> *head_;

  /// Number of items that are currently in the stack.
  size_t count_;
};

/**
 * @class LStack_Iterator
 * @brief Implements a forward iterator for LStack type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying stack!
 */
template <typename T>
class LStack_Iterator 
{
public:
  /// Construct an LStack_Iterator at position pos.  
  LStack_Iterator (LStack<T> &stack,
                   size_t pos = 0);

  /// Construct an LStack_Iterator at node pos.
  LStack_Iterator (LStack<T> &stack,
                   LStack_Node<T> *pos = 0);

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  T& operator* (void);

  /// Returns a const reference to the item contained at the current position
  const T& operator* (void) const;

  /// Preincrement operator
  LStack_Iterator<T> &operator++ (void);

  /// Postincrement operator
  LStack_Iterator<T> operator++ (int);

  /// Equality operator
  bool operator== (const LStack_Iterator<T> &rhs) const;

  /// Nonequality operator
  bool operator!= (const LStack_Iterator<T> &lhs) const;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef int difference_type;

private:
  /// the stack we are dealing with
  LStack<T> &stack_;

  // the position in the linked list
  mutable LStack_Node<T> *pos_;
};

/**
 * @class LStack_Const_Iterator
 * @brief Implements a forward iterator for LStack type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying stack!
 */
template <typename T>
class LStack_Const_Iterator 
{
public:
  /// Construct an LStack_Iterator at position pos.  
  LStack_Const_Iterator (const LStack<T> &stack,
                         size_t pos = 0);

  /// Construct an LStack_Iterator at node pos.  
  LStack_Const_Iterator (const LStack<T> &stack,
                         LStack_Node<T> *pos);

  /// Dereference operator returns a const reference to the item
  /// contained at the current position.
  const T& operator* (void) const;

  /// Preincrement operator
  const LStack_Const_Iterator<T> &operator++ (void) const;

  /// Postincrement operator
  LStack_Const_Iterator<T> operator++ (int) const;

  /// Equality operator
  bool operator== (const LStack_Const_Iterator<T> &rhs) const;

  /// Nonequality operator
  bool operator!= (const LStack_Const_Iterator<T> &lhs) const;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef int difference_type;

private:
  /// the stack we are dealing with
  const LStack<T> &stack_;

  // the position in the linked list
  mutable LStack_Node<T> *pos_;
};

#include "LStack.cpp"

#endif /* _LSTACK_H_ */
