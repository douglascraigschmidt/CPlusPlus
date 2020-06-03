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

stack &
stack::operator=(const stack &rhs) {
  if (this != &rhs) {
    T *temp = new T[rhs.size_];
    stack_ = nullptr;

    for (size_t i = 0; i < rhs.size_; ++i)
      // Subtle bug when generalized to arbitrary type T.
      temp[i] = rhs.stack_[i];

    delete[] stack_;
    stack_ = temp;
    top_ = rhs.top_;
    size_ = rhs.size_;
  }
  return *this;
}

stack::~stack() {
  delete [] stack_;
}

bool
stack::empty() const {
  return top_ == 0;
}

bool
stack::full() const {
  return top_ == size_;
}

void
stack::push(const T &item) {
  stack_[top_++] = item;
}

const T &
stack::top() const {
  return stack_[top_ - 1];
}

T &
stack::top() {
  return stack_[top_ - 1];
}

void
stack::pop() {
  --top_;
}

