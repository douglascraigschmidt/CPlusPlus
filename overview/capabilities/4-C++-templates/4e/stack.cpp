#ifndef _STACK_CPP
#define _STACK_CPP

#include <memory>

template<typename T, size_t SIZE>
stack<T, SIZE>::stack()
  : top_(0) {}

template<typename T, size_t SIZE>
stack<T, SIZE>::stack(const stack<T, SIZE> &rhs)
  : top_(rhs.top_) {
  for (size_t i = 0; i < rhs.top_; ++i)
    stack_[i] = rhs.stack_[i];
}

template<typename T, size_t SIZE>
stack<T, SIZE> &
stack<T, SIZE>::operator=(const stack<T, SIZE> &rhs) {
  if (this != &rhs) {
    for (size_t i = 0; i < rhs.top_; ++i)
      stack_[i] = rhs.stack_[i];
    top_ = rhs.top_;
  }
  return *this;
}

template<typename T, size_t SIZE>
bool
stack<T, SIZE>::empty() const {
  return top_ == 0;
}

template<typename T, size_t SIZE>
bool
stack<T, SIZE>::full() const {
  return top_ == SIZE;
}

template<typename T, size_t SIZE>
void
stack<T, SIZE>::push(const value_type &item) {
  stack_[top_++] = item;
}

template<typename T, size_t SIZE>
void stack<T, SIZE>::push(T &&rval) {
  emplace(std::forward<T>(rval));
}

template<typename T, size_t SIZE>
template<typename... Args>
void
stack<T, SIZE>::emplace(Args &&... args) {
  stack_[top_++] = std::move(T(std::forward<Args>(args) ...));
}

template<typename T, size_t SIZE>
void
stack<T, SIZE>::pop() {
  --top_;
}

template<typename T, size_t SIZE>
const typename stack<T, SIZE>::value_type &
stack<T, SIZE>::top() const {
  return stack_[top_ - 1];
}

template<typename T, size_t SIZE>
typename stack<T, SIZE>::value_type &
stack<T, SIZE>::top() {
  return stack_[top_ - 1];
}

#endif /* _STACK_CPP */

