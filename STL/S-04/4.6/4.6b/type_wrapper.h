#ifndef _TYPE_WRAPPER_H
#define _TYPE_WRAPPER_H

#include <iostream>
using namespace std;

/**
 * This template class is used to demonstrate the difference between
 * pass-by-value and pass-by-reference semantics in C++.
 */
template <typename T>
class type_wrapper {
public:
  type_wrapper() { 
    cout << "type_wrapper::type_wrapper()" << endl; 
  }

  type_wrapper(T i): i_(i) {
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
        T(rhs).swap(*this->i_);
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
