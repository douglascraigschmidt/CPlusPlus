#ifndef _STACK_CPP
#define _STACK_CPP

#include "stack.h"

template<typename T>
stack<T>::stack(size_t size)
  : top_(0),
    size_(size),
    stack_(new T[size]) {
}

template<typename T>
stack<T>::stack(const stack<T> &rhs)
  : top_(rhs.top_),
    size_(rhs.size_),
    stack_(new T[rhs.size_]) {
  for (size_t i = 0; i < rhs.top_; ++i)
    // Yikes, there's a memory leak of T.operator=() throws an
    // exception!
    stack_[i] = rhs.stack_[i];
}

template<typename T>
stack<T>::stack(stack<T> &&rhs) noexcept
        : top_(rhs.top_),
          size_(rhs.size_),
          stack_(rhs.stack_) {
  rhs.stack_ = nullptr;
  rhs.size_ = rhs.top_ = 0;
}

template<typename T>
stack<T> &
stack<T>::operator=(const stack<T> &rhs) {
  if (this != &rhs) {
    T *temp = new T[rhs.size_];

    for (size_t i = 0; i < rhs.top_; ++i)
      // Yikes, there's a memory leak of T.operator=() throws an
      // exception!
      temp[i] = rhs.stack_[i];

    delete [] stack_;
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
    delete [] stack_;
    stack_ = rhs.stack_;
    rhs.stack_ = nullptr;
    rhs.size_ = rhs.top_ = 0;
  }
  return *this;
}

template<typename T>
stack<T>::~stack() {
  delete [] stack_;
}

#endif /* _STACK_CPP */
