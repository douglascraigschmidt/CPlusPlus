/* -*- C++ -*- */
#ifndef _REFCOUNTER_H_
#define _REFCOUNTER_H_

/**
 * @class Refcounter
 * @brief This template class provides transparent reference counting
 *        of its template parameter @a T. 
 *
 *        This class can be used to automate the implementation of the
 *        Bridge pattern in C++.  
 */
template <typename T>
class Refcounter
{
public:
  /// default Ctor
  Refcounter (void);

  /// Ctor with refcounting functionality
  Refcounter (T *ptr, bool increase_count = false);

  /// copy Ctor
  Refcounter (const Refcounter& rhs);

  /// Dtor will delete pointer if refcount becomes 0
  virtual ~Refcounter (void);

  /// assignment operator for times when you don't want
  /// the reference increased for incoming ptr
  void operator= (T *ptr);

  /// assignment operator
  void operator= (const Refcounter &rhs);

  /// dereference operator
  T &operator* (void);

  /// dereference operator
  const T &operator* (void) const;

  /// mimic pointer dereferencing
  T *operator-> (void);

  /// mimic pointer dereferencing
  const T *operator-> (void) const;

  /// get the underlying pointer
  T *get_ptr (void);

  /// get the underlying pointer
  const T *get_ptr (void) const;

private:
  /// implementation of the increment operation
  void increment (void);

  /// implementation of the decrement operation
  void decrement (void);

  /// A shim class that keeps track of the reference count and a
  /// pointer to the type @a T that's reference counted.
  struct Shim
  {
    /// Constructor.
    Shim (T *t);
    
    /// Destructor.
    ~Shim (void);

    /// Pointer to the object that's being reference counted.
    T *t_;

    /// Current value of the reference count.
    int refcount_;
  };

  /// Pointer to the @a Shim.
  Shim *ptr_;
};

#include "Refcounter.cpp"

#endif /* _REFCOUNTER_H_ */
