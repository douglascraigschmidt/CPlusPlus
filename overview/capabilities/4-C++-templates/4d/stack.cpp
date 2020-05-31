#ifndef _STACK_CPP
#define _STACK_CPP

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

template<typename T>
void
stack<T>::swap(stack<T> &rhs) noexcept {
  std::swap(top_, rhs.top_);
  std::swap(size_, rhs.size_);
  stack_.swap(rhs.stack_);
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
stack<T>::push(const value_type &item) {
  stack_[top_++] = item;
}

template<typename T>
void stack<T>::push(T &&rval) {
  emplace(std::forward<T>(rval));
}

template<typename T>
template<typename... Args>
void
stack<T>::emplace(Args &&... args) {
  stack_[top_++] = std::move(T(std::forward<Args>(args) ...));
}

template<typename T>
void
stack<T>::pop() {
  --top_;
}

template<typename T>
const typename stack<T>::value_type &
stack<T>::top() const {
  return stack_[top_ - 1];
}

template<typename T>
typename stack<T>::value_type &
stack<T>::top() {
  return stack_[top_ - 1];
}

#endif /* _STACK_CPP */

