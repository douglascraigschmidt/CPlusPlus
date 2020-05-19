#ifndef _TYPE_WRAPPER_CPP
#define _TYPE_WRAPPER_CPP

using namespace std;

template <typename T>
type_wrapper<T>::type_wrapper() {
  cout << "type_wrapper::type_wrapper()" << endl;
}

template <typename T>
type_wrapper<T>::type_wrapper(T i): i_(i) {
  cout << "type_wrapper::type_wrapper(T)" << endl; 
}

template <typename T>
type_wrapper<T>::type_wrapper(const type_wrapper<T> &rhs) noexcept
  : i_ (rhs.i_) {
  cout << "type_wrapper::type_wrapper(const &)" << endl; 
}

template <typename T>
type_wrapper<T>::type_wrapper(type_wrapper<T> &&rhs) noexcept
  : i_(rhs.i_) {
  cout << "type_wrapper::type_wrapper(&&)" << endl; 
}

template <typename T> type_wrapper<T> &
type_wrapper<T>::operator=(const type_wrapper<T> &rhs) noexcept {
  if (&rhs == this)
    return *this;
  else {
    cout << "type_wrapper::operator=(const &)" << endl;
    return *this;
  }
}

template <typename T>
type_wrapper<T> &
type_wrapper<T>::operator=(type_wrapper<T> &&rhs) noexcept {
  i_ = rhs.i_;
  cout << "type_wrapper::operator=(const &)" << endl;
  return *this;
}

template <typename T> bool 
type_wrapper<T>::operator<(const type_wrapper<T> &rhs) {
  return i_ < rhs.i_;
}

template <typename T>
type_wrapper<T>::operator T() const {
  cout << "type_wrapper::operator T()" << endl;
  return i_;
}

template <typename T>
type_wrapper<T>::~type_wrapper() { 
    cout << "type_wrapper::~type_wrapper" << endl; 
}

#endif /* _TYPE_WRAPPER_CPP */
