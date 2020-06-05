#ifndef _STACK_CPP
#define _STACK_CPP

#include "stack.h"

template<typename T>
stack<T>::stack(size_t size)
  : top_(0),
    size_(size),
    stack_(new T[size]) {}

template<typename T>
stack<T>::stack(const stack<T> &rhs)
  : top_(rhs.top_),
    size_(rhs.size_),
    stack_(new T[rhs.size_]) {
  for (size_t i = 0; i < rhs.size_; ++i)
    stack_[i] = rhs.stack_[i];
}

template<typename T>
stack<T>::stack(stack &&s) noexcept
  : top_(s.top_),
    size_(s.size_),
    stack_(s.stack_.release()) {
  s.size_ = s.top_ = 0;
}

template<typename T>
stack<T> &
stack<T>::operator=(const stack<T> &rhs) {
  if (this != &rhs) {
    stack<T>(rhs).swap(*this);
  }
  return *this;
}

template<typename T>
stack<T> &
stack<T>::operator=(stack<T> &&rhs)  noexcept {
  if (this != &rhs) {
    top_ = rhs.top_;
    size_ = rhs.size_;
    stack_.reset(rhs.stack_.release());
    rhs.size_ = rhs.top_ = 0;
  }
  return *this;
}

#endif /* _STACK_CPP */

