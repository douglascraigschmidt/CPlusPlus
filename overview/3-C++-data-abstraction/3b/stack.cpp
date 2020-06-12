#include "stack.h"

stack::stack(size_t size)
  : top_(0),
    size_(size),
    stack_(new T[size]) {}

stack::stack(const stack &s)
  : top_(s.top_),
    size_(s.size_),
    stack_(new T[s.size_]) {
  for (size_t i = 0; i < s.size_; ++i)
    // Subtle bug when generalized to arbitrary type T.
    stack_[i] = s.stack_[i];
}

stack::stack(stack &&s) noexcept 
  : top_(s.top_),
    size_(s.size_),
    stack_(s.stack_) {
  s.stack_ = nullptr;
  s.size_ = s.top_ = 0;
}

stack &
stack::operator=(const stack &rhs) {
  if (this != &rhs) {
    T *temp = new T[rhs.size_];
    stack_ = nullptr;

    for (size_t i = 0; i < rhs.size_; ++i)
      // Subtle bug when generalized to arbitrary type T.
      temp[i] = rhs.stack_[i];

    delete [] stack_;
    stack_ = temp;
    top_ = rhs.top_;
    size_ = rhs.size_;
  }
  return *this;
}

stack &
stack::operator=(stack &&rhs)  noexcept {
  if (this != &rhs) {
    top_ = rhs.top_;
    size_ = rhs.size_;
    delete [] stack_;
    stack_ = rhs.stack_;
    rhs.stack_ = nullptr;
    rhs.size_ = rhs.top_ = 0;
  }
  return *this;
}

stack::~stack() {
  delete [] stack_;
}


