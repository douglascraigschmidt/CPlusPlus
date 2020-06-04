#ifndef _STACK_CPP
#define _STACK_CPP

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

#endif /* _STACK_CPP */

