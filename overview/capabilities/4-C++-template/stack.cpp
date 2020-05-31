#ifndef _STACK_CPP
#define _STACK_CPP

#include "stack.h"

template<typename T>
stack<T>::stack(size_t size)
  : top_(0),
    size_(size),
    stack_(new T[size]) {}

template<typename T>
stack<T>::stack(const stack<T> &s)
  : top_(s.top_),
    size_(s.size_),
    stack_(new T[s.size_]) {
  for (size_t i = 0; i < s.size_; ++i)
    // Subtle bug when generalized to arbitrary type T.
    stack_[i] = s.stack_[i];
}

template<typename T>
stack<T>::stack(stack &&s) noexcept
        : top_(s.top_),
          size_(s.size_),
          stack_(s.stack_) {
  s.stack_ = nullptr;
  s.size_ = s.top_ = 0;
}

template<typename T>
stack<T> &
stack<T>::operator=(const stack<T> &rhs) {
  if (this != &rhs) {
    T *temp = new T[rhs.size_];
    stack_ = nullptr;

    for (size_t i = 0; i < rhs.size_; ++i)
      temp[i] = rhs.stack_[i];
    // Subtle bug when generalized to arbitrary type T.

    delete[] stack_;
    stack_ = temp;
    top_ = rhs.top_;
    size_ = rhs.size_;
  }
  return *this;
}

template<typename T>
stack<T> &
stack<T>::operator=(stack<T> &&rhs)  noexcept {
  if (this != &rhs) {
    top_ = rhs.top_;
    size_ = rhs.size_;
    stack_ = rhs.stack_;
    stack_ = nullptr;
    rhs.size_ = rhs.top_ = 0;
  }
  return *this;
}

template<typename T>
stack<T>::~stack() {
  delete [] stack_;
}

template<typename T>
bool
stack<T>::is_empty() const {
  return top_ == 0;
}

template<typename T>
bool
stack<T>::is_full() const {
  return top_ == size_;
}

template<typename T>
void
stack<T>::push(const T &item) {
  stack_[top_++] = item;
}

template<typename T>
void
stack<T>::pop() {
  --top_;
}

template<typename T>
void
stack<T>::top(T &item) const {
  item = stack_[top_ - 1];
}

#endif /* _STACK_CPP */

