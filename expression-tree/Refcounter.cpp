/* -*- C++ -*- */
#ifndef _REFCOUNTER_CPP_
#define _REFCOUNTER_CPP_

#include "Refcounter.h"

/// default Ctor
template <typename T>
Refcounter<T>::Refcounter (void)
  : ptr_ (0)
{
}

/// Ctor with refcounting functionality
template <typename T>
Refcounter<T>::Refcounter (T *ptr, bool increase_count)
  : ptr_ (new Shim (ptr))
{
  if (increase_count)
    increment ();
}

  /// copy Ctor
template <typename T>
Refcounter<T>::Refcounter (const Refcounter &rhs)
  : ptr_ (rhs.ptr_)
{
  increment ();
}

  /// Dtor will delete pointer if refcount becomes 0
template <typename T>
Refcounter<T>::~Refcounter (void)
{
  decrement ();
}

/// assignment operator for times when you don't want the reference
/// increased for incoming ptr.
template <typename T>
void 
Refcounter<T>::operator= (T *ptr)
{
  decrement ();
  ptr_ = new Shim (ptr);
}

  /// assignment operator
template <typename T>
void
Refcounter<T>::operator= (const Refcounter& rhs)
{
  decrement ();
  ptr_ = rhs.ptr_;
  increment ();
}

/// get the underlying pointer
template <typename T>
T * 
Refcounter<T>::get_ptr (void)
{
  return ptr_->t_;
}

/// get the underlying pointer
template <typename T>
const T *
Refcounter<T>::get_ptr (void) const
{
  return ptr_->t_;
}


/// dereference operator
template <typename T>
T & 
Refcounter<T>::operator* (void)
{
  return *ptr_->t_;
}

/// dereference operator
template <typename T>
const 
T &
Refcounter<T>::operator* (void) const
{
  return *ptr_->t_;
}

/// mimic pointer dereferencing
template <typename T>
T *
Refcounter<T>::operator-> (void)
{
  return ptr_->t_;
}

/// mimic pointer dereferencing
template <typename T>
const T *
Refcounter<T>::operator-> (void) const
{
  return ptr_->t_;
}

/// implementation of the increment operation
template <typename T>
void 
Refcounter<T>::increment (void)
{
  if (ptr_)
    ++ptr_->refcount_;
}

  /// implementation of the decrement operation
template <typename T>
void 
Refcounter<T>::decrement (void)
{
  if (ptr_)
    {
      --ptr_->refcount_;
      if (ptr_->refcount_ <= 0)
        {
          delete ptr_;
          ptr_ = 0;
        }
    }
}

template <typename T>
Refcounter<T>::Shim::Shim (T *t)
  : t_ (t), refcount_ (1) 
{
}

template <typename T>
Refcounter<T>::Shim::~Shim (void) 
{ 
  delete t_; 
}

#endif /* _REFCOUNTER_CPP_ */
