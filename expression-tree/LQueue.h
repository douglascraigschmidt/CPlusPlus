/* -*- C++ -*- */
#ifndef _LQUEUE_H
#define _LQUEUE_H

// This header defines "size_t"
#include <stdlib.h>

#include <stdexcept>

// Solve circular include problem via forward decls.
template <typename T>
class LQueue_Node;

template <typename T>
class LQueue_Iterator;

template <typename T>
class LQueue_Const_Iterator;

/**
 * @class LQueue
 * @brief Defines a generic "first-in/first-out" (FIFO) Abstract Data
 *        Type (ADT) using a circular linked list.
 *
 *        This queue is a circular linked list where the @a tail_
 *        pointer points to a dummy node which makes implementation
 *        much easier (particularly iterator traversal).  When
 *        enqueuing an item, the dummy node contains the new item and
 *        points to a new dummy node.  The head of the list is thsu
 *        always @a tail_->next_.  Dequeuing an object gets rid of the
 *        head node and makes the dummy node point to the new head.
 */
template <class T> 
class LQueue
{
  friend class LQueue_Iterator<T>;
  friend class LQueue_Const_Iterator<T>;
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
   * @class Overflow
   * @brief Exception thrown by methods in this class when an overflow
   *        condition occurs.  
   */
  class Overflow {};

  /// Constructor.
  LQueue (size_t size_hint = 0);

  /// Copy constructor.
  LQueue (const LQueue<T> &rhs);

  /// Assignment operator.
  LQueue<T> &operator = (const LQueue<T> &rhs);

  /// Perform actions needed when queue goes out of scope. 
  ~LQueue (void);


  /// Place a @a new_item at the tail of the queue.  Throws the @a
  /// Overflow exception if the queue is full, e.g., if memory is
  /// exhausted.
  void enqueue (const T &new_item);

  /// Remove and return the front item on the queue.  Throws the @a
  /// Underflow exception if the queue is empty.
  T dequeue (void);

  /// Returns the front queue item without removing it.  Throws the @a
  /// Underflow exception if the queue is empty.
  T front (void) const;

  /// Returns 1 if the queue is empty, otherwise returns 0. 
  bool is_empty (void) const;

  /// Returns 1 if the queue is full, otherwise returns 0. 
  bool is_full (void) const;

  /// Returns the current number of elements in the queue.
  size_t size (void) const;

  /// Compare this queue with @a rhs for equality.  Returns true if
  /// the sizes of the two queues are equal and all the elements from
  /// 0 .. size() are equal, else false.
  bool operator== (const LQueue<T> &rhs) const;

  /// Compare this queue with @a rhs for inequality such that @a
  /// *this>!=s is always the complement of the boolean return value
  /// of @a *this==s.
  bool operator!= (const LQueue<T> &s) const;

  typedef LQueue_Iterator<T> iterator;
  typedef LQueue_Const_Iterator<T> const_iterator;

  /// Get an iterator that points to the beginning of the queue.
  iterator begin (void);

  /// Get a const iterator that points to the beginning of the queue.
  const_iterator begin (void) const;

  /// Get an iterator that points to the end of the queue.
  iterator end (void);

  /// Get a const iterator that points to the end of the queue.
  const_iterator end (void) const;

protected:
  /// Remove the front item on the queue.  Does not throw exceptions.
  void dequeue_i (void);

  // Copy a linked list of nodes.  This can throw a @a std::bad_alloc
  // exception.
  void copy_list (const LQueue<T> &rhs);

  // Delete a linked list of nodes.
  void delete_list (void);

private:
  /// We only need to keep a single pointer for the circular linked
  /// list.  This points to the tail of the queue.  Since the list is
  /// circular, the head of the queue is always @a tail_->next_.
  LQueue_Node<T> *tail_;

  /// Number of items that are currently in the queue.
  size_t count_;

};

/**
 * @class LQueue_Iterator
 * @brief Implements a forward iterator for LQueue type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying queue!
 */
template <typename T>
class LQueue_Iterator 
{
public:
  /// Construct an LQueue_Iterator at position pos.  
  LQueue_Iterator (LQueue<T> &queue,
                   size_t pos = 0);

  /// Construct an LQueue_Iterator at node pos.
  LQueue_Iterator (LQueue<T> &queue,
                   LQueue_Node<T> *pos = 0);

  /// Dereference operator returns a reference to the item contained
  /// at the current position
  T& operator* (void);

  /// Returns a const reference to the item contained at the current position
  const T& operator* (void) const;

  /// Preincrement operator
  LQueue_Iterator<T> &operator++ (void);

  /// Postincrement operator
  LQueue_Iterator<T> operator++ (int);

  /// Equality operator
  bool operator== (const LQueue_Iterator<T> &rhs) const;

  /// Nonequality operator
  bool operator!= (const LQueue_Iterator<T> &lhs) const;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef int difference_type;

private:
  /// the queue we are dealing with
  LQueue<T> &queue_;

  // the position in the linked list
  mutable LQueue_Node<T> *pos_;
};

/**
 * @class LQueue_Const_Iterator
 * @brief Implements a forward iterator for LQueue type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying queue!
 */
template <typename T>
class LQueue_Const_Iterator 
{
public:
  /// Construct an LQueue_Iterator at position pos.  
  LQueue_Const_Iterator (const LQueue<T> &queue,
                         size_t pos = 0);

  /// Construct an LQueue_Iterator at node pos.  
  LQueue_Const_Iterator (const LQueue<T> &queue,
                         LQueue_Node<T> *pos);

  /// Dereference operator returns a const reference to the item
  /// contained at the current position.
  const T& operator* (void) const;

  /// Preincrement operator
  const LQueue_Const_Iterator<T> &operator++ (void) const;

  /// Postincrement operator
  LQueue_Const_Iterator<T> operator++ (int) const;

  /// Equality operator
  bool operator== (const LQueue_Const_Iterator<T> &rhs) const;

  /// Nonequality operator
  bool operator!= (const LQueue_Const_Iterator<T> &lhs) const;

  // = Necessary traits
  typedef std::forward_iterator_tag iterator_category;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef int difference_type;

private:
  /// the queue we are dealing with
  const LQueue<T> &queue_;

  // the position in the linked list
  mutable LQueue_Node<T> *pos_;
};

#include "LQueue.cpp"
#endif /* _LQUEUE_H */
