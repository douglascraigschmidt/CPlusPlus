#include <iostream>
using namespace std;

template <typename T>
class type_wrapper {
public:
  type_wrapper() { cout << "type_wrapper::type_wrapper()" << endl; }

  type_wrapper(T i): i_(i) { cout << "type_wrapper::type_wrapper(int)" << endl; }

  type_wrapper(const type_wrapper &f): i_ (f.i_) { cout << "type_wrapper::type_wrapper(const &)" << endl; }

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

  ~type_wrapper() { cout << "type_wrapper::~type_wrapper" << endl; }

  T i_;
};
