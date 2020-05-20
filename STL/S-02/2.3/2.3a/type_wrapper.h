#ifndef _TYPE_WRAPPER_H
#define _TYPE_WRAPPER_H

#include <iostream>
using namespace std;

/**
 * The declaration of C++ class templates must begin with the keyword
 * template.  A parameter must be included inside angle brackets using
 * either the keyword class or typename. Additional parameters can be
 * included within the angle brackets, including non-typed parameters
 * and other templates as parameters.  Just like any class, the class
 * body declaration with its member data and member functions follows.
 *
 * This template class is used to demonstrate the difference between
 * pass-by-value and pass-by-reference semantics in C++.
 */
template <typename T>
class type_wrapper {
public:
  type_wrapper();
  explicit type_wrapper(T i);
  type_wrapper(const type_wrapper<T> &rhs) noexcept;
  type_wrapper(type_wrapper<T> &&rhs) noexcept;
  type_wrapper<T> &operator=(const type_wrapper<T> &rhs) noexcept;
  type_wrapper<T> &operator=(type_wrapper<T> &&rhs) noexcept;
  bool operator<(const type_wrapper<T> &rhs);
  operator T() const;
  ~type_wrapper();

private:
  T i_;
};

#include "type_wrapper.cpp"

#endif /* _TYPE_WRAPPER_H */
