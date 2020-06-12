#include <iostream>
#include <cstring>
#include "simple_string.h"

using namespace std;

std::ostream &
operator<<(std::ostream &os, const simple_string &string) {
  return os << (const char *) string;
}

/**
 * This simple string class is used to demonstrate the difference
 * between copy vs. move semantics in C++ when passing objects by
 * value.  It also demonstrates the "Rule of 5", which supplants the
 * previous "Rule of 3" with C++
 * https://en.wikipedia.org/wiki/Rule_of_three_(C++_programming).
 */
simple_string::simple_string()
    : len_(0),
      str_ (nullptr) {
  cout << "simple_string::simple_string()" << endl; 
}

simple_string::simple_string(const char *s)
  : len_(0),
    str_(strnew(s)) {
  cout << "simple_string::simple_string(const char *)" << endl;
}

simple_string::simple_string(const simple_string &rhs) noexcept
  : len_(0),
    str_(strnew(rhs.str_)) {
  cout << "simple_string::simple_string(const &)" << endl; 
}

simple_string::simple_string(simple_string &&rhs) noexcept
  : len_(rhs.len_),
    str_(rhs.str_) {
  cout << "simple_string::simple_string(simple_string &&)" << endl;
  rhs.str_ = nullptr;
  rhs.len_ = 0;
}

simple_string &
simple_string::operator=(const simple_string &rhs) noexcept {
  cout << "simple_string::operator=(const simple_string &)" << endl;
  if (&rhs != this) {
    simple_string(rhs).swap(*this);
  }
  return *this;
}

simple_string &
simple_string::operator=(simple_string &&rhs) noexcept {
    cout << "simple_string::operator=(simple_string &&)" << endl;
  if (&rhs != this) {
    len_ = rhs.len_;
    delete [] str_;
    str_ = rhs.str_;
    rhs.len_ = 0;
    rhs.str_ = nullptr;
  }
  return *this;
}

void 
simple_string::swap(simple_string &rhs) noexcept {
  std::swap(len_, rhs.len_);
  std::swap(str_, rhs.str_);
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

size_t
simple_string::length() const {
    return len_;
}

bool
simple_string::operator<(const simple_string &rhs) const {
    return strcmp(str_, rhs.str_) < 0;
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
  if (s != nullptr) {
    len_ = strlen(s);
    return strcpy(new char[len_ + 1], s);
  } else
    return nullptr;
}

