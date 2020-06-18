/* -*- C++ -*- */

#ifndef _ARRAY_H
#define _ARRAY_H

// This header defines "size_t"
#include <stdlib.h>
#include <stdexcept>
#include <algorithm>
#include <memory>

// Solve circular include problem via forward decls.
template <typename T>
class Array_Iterator;

template <typename T>
class Const_Array_Iterator;

/**
 * @class Array
 * @brief Implements a resizeable generic array class.
 */
template <typename T>
class Array
{
public:
  // Define some class "traits"
  typedef T value_type;
  typedef Array_Iterator<T> iterator;
  typedef const Const_Array_Iterator<T> const_iterator;

  // = Initialization and termination methods.

  // Dynamically create an uninitialized array.  Throws <std::bad_alloc>
  // if allocation fails.
  explicit Array (size_t size = 1);

  // Dynamically initialize the entire array to the <default_value>.
  // Throws <std::bad_alloc> if allocation fails.
  Array (size_t size,
         const T &default_value);

  // The copy constructor performs initialization by making an exact
  // copy of the contents of parameter <s>, i.e., *this == s will
  // return true.  Throws <std::bad_alloc> if allocation fails.
  Array (const Array<T> &s);

#if defined(RVALUE_REFERENCES)
  // The move constructor (performs move vs. copy semantics).
  Array (Array<T> &&rhs);
#endif /* RVALUE_REFERENCES */

  // Assignment operator performs an assignment by making a copy of
  // the contents of parameter <s>, i.e., *this == s will return true.
  // Throws <std::bad_alloc> if allocation fails.
  Array<T> &operator= (const Array<T> &s);

#if defined(RVALUE_REFERENCES)
  // The move assignment operator (performs move vs. copy semantics).
  Array<T> &operator= (Array<T> &&rhs);
#endif /* RVALUE_REFERENCES */

  // Destructor is a no-op in this implementation
  ~Array ();

  // Get an iterator that points to the beginning of the Array.
  iterator begin ();

  // Get a const interator that points to the beginning of the Array.
  const_iterator begin () const;

  // Get an iterator that points to the end
  iterator end ();

  // Get a const iterator that points to the end of the list.
  const_iterator end () const;

  // = Set/get methods.

  // Set an item in the array at location index.  If <index> >
  // <s.cur_size_> then <resize()> the array so it's big enough.
  // Throws <std::bad_alloc> if resizing the array fails.
  void set (const T &new_item, size_t index);

  // Adds <value> to the end of the Array, increasing the size if
  // necessary.
  void push_back(const T &value);

  // Get an item in the array at location index.  Throws
  // <std::out_of_range> of index is not <in_range>.
  void get (T &item, size_t index) const;

  // Returns the <cur_size_> of the array.
  size_t size () const;

  // Returns a reference to the <index> element in the <Array> without
  // checking for range errors.
  const T &operator[] (size_t index) const;

  // Set an item in the array at location index without 
  // checking for range errors.
  T &operator[] (size_t index);

  // Compare this array with <s> for equality.  Returns true if the
  // size()'s of the two arrays are equal and all the elements from 0
  // .. size() are equal, else false.
  bool operator== (const Array<T> &s) const;

  // Compare this array with <s> for inequality such that <*this> !=
  // <s> is always the complement of the boolean return value of
  // <*this> == <s>.
  bool operator!= (const Array<T> &s) const;

  // Change the size of the array to be at least <new_size> elements.
  // Throws <std::bad_alloc> if allocation fails.
  void resize (size_t new_size);

  // Efficiently swap the contents of this array with <new_array>.
  // Does not throw an exception.
  void swap (Array<T> &new_array);

private:
  // Returns true if <index> is within range, i.e., 0 <= <index> <
  // <cur_size_>, else returns false.
  bool in_range (size_t index) const;

  // Maximum size of the array, i.e., the total number of <T> elements
  // in <array_>.
  size_t max_size_;
        
  // Current size of the array.  This starts out being == to
  // <max_size_>.  However, if we are assigned a smaller array, then
  // <cur_size_> will become less than <max_size_>.  The purpose of
  // keeping track of both sizes is to avoid reallocating memory if we
  // don't have to.
  size_t cur_size_;

  // Index where the next push_back() occurs.
  size_t next_push_back_index_;

  // If a default value is needed, keep track of its value.
  std::unique_ptr<T> default_value_;

  // Pointer to the array's storage buffer.
  std::unique_ptr<T> array_;
};

/**
 * @class Array_Iterator
 * @brief Implements a bidirectional iterator for array type classes.
 *
 * Note:  Having a const Iterator does not guarantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying array!
 */
template <typename T>
class Array_Iterator
  : public std::iterator<std::bidirectional_iterator_tag, Array<T>>
{
  friend class Array<T>;
private:
  /// Construct an Array_Iterator at position pos.  
  Array_Iterator (Array<T> &array, size_t pos = 0);

public:
  /// Dereference operator returns a reference to the item contained
  /// at the current position
  T& operator* ();

  /// Returns a const reference to the item contained at the current position
  const T& operator* () const;

  /// Preincrement operator
  Array_Iterator<T> &operator++ ();

  /// Postincrement operator
  Array_Iterator<T> operator++ (int);

  /// Predecrement operator
  Array_Iterator<T> &operator-- ();

  /// Posdecrement operator
  Array_Iterator<T> operator-- (int);

  /// Equality operator
  bool operator== (const Array_Iterator<T> &rhs) const;

  /// Nonequality operator
  bool operator!= (const Array_Iterator<T> &lhs) const;

  // = Necessary traits
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T value_type;
  typedef T *pointer;
  typedef T &reference;
  typedef int difference_type;

private:
  /// the array we are dealing with
  Array<T> &array_;

  /// Our current position
  mutable size_t pos_;
};

/**
 * @class Const_Array_Iterator
 * @brief Implements a bidirectional iterator for array type classes.
 *
 * Note:  Having a const Iterator does not gaurantee that the current
 * *position* that it points to will not change, it only guarantees that
 * you cannot change the underlying array!
 */
template <typename T>
class Const_Array_Iterator
  : public std::iterator<std::bidirectional_iterator_tag,
                         Array<T>>
{
  friend class Array<T>;
private:
  /// Construct an iterator at position pos.
  Const_Array_Iterator (const Array<T> &array, size_t pos = 0);

public:
  /// Returns a const reference to the item contained at the current position.
  const T& operator* () const;

  /// Preincrement operator
  const Const_Array_Iterator<T> &operator++ () const;

  /// Postincrement operator
  Const_Array_Iterator<T> operator++ (int) const;

  /// Predecrement operator
  const Const_Array_Iterator &operator-- () const;

  /// Postdecrement operator
  Const_Array_Iterator<T> operator-- (int) const;

  /// Equality operator
  bool operator== (const Const_Array_Iterator<T> &rhs) const;

  /// Nonequality operator
  bool operator!= (const Const_Array_Iterator<T> &lhs) const;

private:
  /// the array we are dealing with
  const Array<T> &array_;

  /// Our current position
  mutable size_t pos_;
};

#if defined (__INLINE__)
#define INLINE inline
#include "Array.inl"
#endif /* __INLINE__ */

#include "Array.cpp"

#endif /* _ARRAY_H */
