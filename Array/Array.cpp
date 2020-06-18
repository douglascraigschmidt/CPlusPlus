#ifndef _ARRAY_CPP
#define _ARRAY_CPP

#include <sys/types.h>
// #include "Array.h"

#if !defined (__INLINE__)
#define INLINE 
#include "Array.inl"
#endif /* __INLINE__ */

#include <algorithm>
#include <sstream>
#include <iostream>

template <typename T> 
Array<T>::Array (size_t size)
  : max_size_ (size),
    cur_size_ (size),
    next_push_back_index_ (0),
    default_value_ (nullptr),
    array_ (new T[size]) {
  std::cout << "Array(size_t)" << std::endl;  
}

template <typename T> 
Array<T>::Array (size_t size, 
		 const T &default_value)
  : max_size_ (size),
    cur_size_ (size),
    next_push_back_index_ (0),
    default_value_ (new T (default_value)),
    array_ (new T[size]) {
  std::cout << "Array(size_t, const T)" << std::endl;  
  std::fill_n (array_.get (),
               size,
               default_value);
}

// The copy constructor (performs initialization).

template <typename T> 
Array<T>::Array (const Array<T> &rhs)
   : max_size_ (rhs.cur_size_),
     cur_size_ (rhs.cur_size_),
     next_push_back_index_ (rhs.next_push_back_index_),
     default_value_ (rhs.default_value_
                     ? new T (*rhs.default_value_) 
                     : nullptr),
     array_ (new T[rhs.cur_size_]) {
  std::cout << "Array(const Array<T> &)" << std::endl;

  // If an exception is thrown here the destructors of the data
  // members clean everything up.
  std::copy (rhs.array_.get (),
             rhs.array_.get () + rhs.cur_size_,
             array_.get ());
}

// The move constructor (performs moves vs. copying).

#if defined(RVALUE_REFERENCES)

template <typename T> 
Array<T>::Array (Array<T> &&rhs)
  : max_size_ (rhs.max_size_),
    cur_size_ (rhs.cur_size_),
    next_push_back_index_ (rhs.next_push_back_index_),
    default_value_ (rhs.default_value_.release()),
    array_ (rhs.array_.release())
{
  std::cout << "Array(Array<T> &&)" << std::endl;  
}

#endif /* RVALUE_REFERENCES */

template <typename T> void
Array<T>::resize (size_t new_size) {
  if (new_size > max_size_) {
    // Create a new temp array, copy the old items into the temp
    // array, and delete the old array via the destructor of
    // scoped_array to ensure strong exception handling semantics.
    size_t physical_size = std::max (new_size, max_size_ * 2);

    std::unique_ptr<T> temp_array (new T[physical_size]);

    std::copy (array_.get (),
               array_.get () + cur_size_,
               temp_array.get ());

    max_size_ = physical_size;
    // If we're using a default value make sure to initialize the
    // newly resized array properly if that's necessary.
    if (default_value_.get () != nullptr && cur_size_ < new_size)
      std::fill_n (temp_array.get () + cur_size_,
                   new_size - cur_size_,
                   *default_value_);

    temp_array.swap (array_);
  } else if (cur_size_ < new_size) {
    std::unique_ptr<T> temp_array (new T[new_size]);

    std::copy (array_.get (),
               array_.get () + cur_size_,
               temp_array.get ());

    max_size_ = new_size;

    if (default_value_.get () != nullptr)
      std::fill_n (temp_array.get () + cur_size_,
                   new_size - cur_size_,
                   *default_value_);

    temp_array.swap (array_);
  }

  // We always update the cur_size_ to make the call to resize()
  // visible.
  cur_size_ = new_size;
}

template <typename T> void
Array<T>::swap (Array<T> &new_array) {
  // All these calls have "no throw" exception semantics.
  std::swap (max_size_, new_array.max_size_);
  std::swap (cur_size_, new_array.cur_size_);
  std::swap (next_push_back_index_, new_array.next_push_back_index_);
  std::swap (default_value_, new_array.default_value_);
  array_.swap (new_array.array_);
}

// Move assignment operator (performs assignment). 

template <typename T> Array<T> &
Array<T>::operator= (const Array<T> &rhs) {
  std::cout << "operator=(const Array<T> &)" << std::endl;  
  // Check for "self-assignment".
  if (this != &rhs) {
    // Create a temp array and then perform a swap to ensure strong
    // exception safety guarantees.
    Array<T>(rhs).swap(*this);
  }
  return *this;
}

#if defined (RVALUE_REFERENCES)
template <typename T> Array<T> &
Array<T>::operator= (Array<T> &&rhs) {
  std::cout << "operator=(Array<T> &&)" << std::endl;  
  // Simply swap the rsh with this!
  swap(rhs);
}
#endif /* RVALUE_REFERENCES */

template <typename T> 
Array<T>::~Array (void) {
  // Destructor is a no-op - just print some diagnostics.

  if (array_.get() == 0)
    std::cout << "null ~Array" << std::endl;  
  else
    std::cout << "~Array" << std::endl;  
}

// Set an item in the array at location index.  

template <typename T> void
Array<T>::set (const T &new_item, size_t index) {
  if (!in_range (index))
    resize (index + 1);

  (*this)[index] = new_item;
}

template <typename T> void
Array<T>::push_back (const T &new_item) {
  set (new_item, next_push_back_index_++);
}

// Get an item in the array at location index.

template <typename T> void
Array<T>::get (T &item, size_t index) const {
  if (in_range (index))
    item = (*this)[index];
  else {
    std::stringstream index_str;
    index_str << static_cast <int> (index);
    throw std::out_of_range (index_str.str ());
  }
}

// Compare this array with <s> for equality.

template <typename T> bool
Array<T>::operator== (const Array<T> &s) const {
  return cur_size_ == s.cur_size_
    && std::equal (array_.get (),
                   array_.get () + cur_size_,
                   s.array_.get ());
}

// Compare this array with <s> for inequality.

template <typename T> bool
Array<T>::operator!= (const Array<T> &s) const {
  return !(*this == s);
}

template <typename T>
Array_Iterator<T>::Array_Iterator (Array<T> &array, size_t pos)
  : array_ (array),
    pos_ (pos)
{}

template <typename T>
Const_Array_Iterator<T>::Const_Array_Iterator (const Array<T> &array, size_t pos)
  : array_ (array),
    pos_ (pos)
{}

#endif /* _ARRAY_CPP */
