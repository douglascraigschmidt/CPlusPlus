#ifndef _STACK_CPP
#define _STACK_CPP

#include <memory>

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container>::stack(size_t size)
  : size_(size),
    stack_(size) {}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container>::stack(const stack<T, sequential_container> &rhs)
  : size_(rhs.size_),
    stack_(rhs.stack_.size()) {
  for (size_t i = 0; i < rhs.stack_.size(); ++i)
    stack_[i] = rhs.stack_[i];
}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container>::stack(stack &&rhs) noexcept
  : size_(rhs.size_),
    stack_(rhs.stack_) {
}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container> &
stack<T, sequential_container>::operator=(const stack<T, sequential_container> &rhs) {
  if (this != &rhs) {
    stack<T, sequential_container>(rhs).swap(*this);
  }
  return *this;
}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container> &
stack<T, sequential_container>::operator=(stack<T, sequential_container> &&rhs)  noexcept {
  if (this != &rhs) {
    size_ = rhs.size_;
    stack_ = rhs.stack_;
  }
  return *this;
}

template<typename T, template <typename ...> class sequential_container>
void
stack<T, sequential_container>::swap(stack<T, sequential_container> &rhs) noexcept {
  std::swap(size_, rhs.size_);
  stack_.swap(rhs.stack_);
}

template<typename T, template <typename ...> class sequential_container>
bool
stack<T, sequential_container>::empty() const {
  return stack_.empty();
}

template<typename T, template <typename ...> class sequential_container>
bool
stack<T, sequential_container>::full() const {
  return stack_.size() == size_;
}

template<typename T, template <typename ...> class sequential_container>
void
stack<T, sequential_container>::push(const value_type &item) {
  stack_.push_back(item);
}

template<typename T, template <typename ...> class sequential_container>
void stack<T, sequential_container>::push(T &&rval) {
  stack_.push_back(rval);
}

template<typename T, template <typename ...> class sequential_container>
template<typename... Args>
void
stack<T, sequential_container>::emplace(Args &&... args) {
  stack_.emplace_back(std::move(T(std::forward<Args>(args) ...)));
}

template<typename T, template <typename ...> class sequential_container>
void
stack<T, sequential_container>::pop() {
  stack_.pop_back();
}

template<typename T, template <typename ...> class sequential_container>
const typename stack<T, sequential_container>::value_type &
stack<T, sequential_container>::top() const {
  return stack_.back();
}

template<typename T, template <typename ...> class sequential_container>
typename stack<T, sequential_container>::value_type &
stack<T, sequential_container>::top() {
  return stack_.back();
}

#endif /* _STACK_CPP */

