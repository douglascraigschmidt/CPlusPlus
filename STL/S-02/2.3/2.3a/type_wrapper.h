#ifndef _TYPE_WRAPPER_H
#define _TYPE_WRAPPER_H

#include <iostream>
using namespace std;

/**
 * The declaration of C++ class templates must begin with the keyword
 * template.  A parameter must be included inside angle brackets using
 * either the keyword class or typename. Additional parameters can be
 * incuded within the angle brackets, including non-typed parameters
 * and other templates as parameters.  Just like any class, the class
 * body declaration with its member data and member functions follows.
 *
 * This template class is used to demonstrate the difference between
 * pass-by-value and pass-by-reference semantics in C++.
 */
template <typename T>
class type_wrapper {
public:
  type_wrapper() { 
    cout << "type_wrapper::type_wrapper()" << endl; 
  }

  explicit type_wrapper(T i): i_(i) {
    cout << "type_wrapper::type_wrapper(T)" << endl; 
  }

  type_wrapper(const type_wrapper<T> &rhs) noexcept: i_ (rhs.i_) {
    cout << "type_wrapper::type_wrapper(const &)" << endl; 
  }

  type_wrapper(type_wrapper<T> &&rhs) noexcept: i_(rhs.i_) {
    cout << "type_wrapper::type_wrapper(&&)" << endl; 
  }

  type_wrapper<T> &operator=(const type_wrapper<T> &rhs) noexcept {
    if (&rhs == this)
        return *this;
    else {
        cout << "type_wrapper::operator=(const &)" << endl;
        return *this;
    }
  }

  type_wrapper<T> &operator=(type_wrapper<T> &&rhs) noexcept {
    i_ = rhs.i_;
    cout << "type_wrapper::operator=(const &)" << endl;
    return *this;
  }

  bool operator<(const type_wrapper<T> &rhs) {
    return i_ < rhs.i_;
  }

  operator T() const {
    return i_;
  }

  ~type_wrapper() { 
    cout << "type_wrapper::~type_wrapper" << endl; 
  }

private:
  T i_;
};
#endif /* _TYPE_WRAPPER_H */
