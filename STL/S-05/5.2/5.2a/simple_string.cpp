#include <iostream>
#include <cstring>
#include "simple_string.h"

using namespace std;

/**
 * This simple string class is used to demonstrate the difference
 * between copy vs. move semantics in C++ when passing objects by value.  It
 * also demonstrates the "Rule of 5", which supplants the previous
 * "Rule of 3" with C++
 * https://en.wikipedia.org/wiki/Rule_of_three_(C++_programming).
 */
simple_string::simple_string(): str_ (nullptr) {
  cout << "simple_string::simple_string()" << endl; 
}

simple_string::simple_string(const char *s)
  : str_(strnew(s)) {
  cout << "simple_string::simple_string(const char *)" << endl;
}

simple_string::simple_string(const simple_string &rhs) noexcept
  : str_ (strnew(rhs.str_)) {
  cout << "simple_string::simple_string(const &)" << endl; 
}

simple_string::simple_string(simple_string &&rhs) noexcept:
  str_(nullptr) {
  cout << "simple_string::simple_string(simple_string &&)" << endl;
  str_ = rhs.str_;
  rhs.str_ = nullptr;
}

simple_string &
simple_string::operator=(const simple_string &rhs) noexcept {
    cout << "simple_string::operator=(const &)" << endl;
  if (&rhs == this)
    return *this;
  else {
    simple_string(rhs).swap(*this);
    return *this;
  }
}

simple_string &
simple_string::operator=(simple_string &&rhs) noexcept {
    cout << "simple_string::operator=(simple_string &&)" << endl;
  if (&rhs == this)
    return *this;
  else {
    rhs.swap(*this);
    return *this;
  }
}

void 
simple_string::swap(simple_string &rhs) noexcept {
  char *temp = str_;
  str_ = rhs.str_;
  rhs.str_ = temp;
  cout << "simple_string::swap(simple_string &)" << endl;
}

char &
simple_string::operator[](size_t index) {
  return str_[index];
}

const char &
simple_string::operator[](size_t index) const {
  return str_[index];
}

simple_string::operator const char *() const {
  return str_;
}

simple_string::~simple_string() {
  cout << "simple_string::~simple_string";

  delete [] str_;

  if (str_ == nullptr)
    cout << "(nullptr)";

  cout << endl;   
}

char *simple_string::strnew(const char *s) {
    return strcpy(new char[strlen(s) + 1], s);
}

