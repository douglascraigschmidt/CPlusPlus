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

  type_wrapper(T i): i_(i) {
    cout << "type_wrapper::type_wrapper(int)" << endl; 
  }

  type_wrapper(const type_wrapper &f): i_ (f.i_) {
    cout << "type_wrapper::type_wrapper(const &)" << endl; 
  }

  void operator=(const type_wrapper &rhs) {
    i_ = rhs.i_;
    cout << "type_wrapper::operator=(const &)" << endl;
  }

  bool operator<(const type_wrapper &rhs) {
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
