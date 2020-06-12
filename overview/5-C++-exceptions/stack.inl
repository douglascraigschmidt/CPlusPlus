#ifndef _STACK_INL
#define _STACK_INL

template<typename T>
inline void
stack<T>::swap(stack<T> &rhs) noexcept {
  std::swap(top_, rhs.top_);
  std::swap(size_, rhs.size_);
  stack_.swap(rhs.stack_);
}

template<typename T>
inline bool
stack<T>::empty() const {
  return top_ == 0;
}

template<typename T>
inline bool
stack<T>::full() const {
  return top_ == size_;
}

template<typename T>
inline void
stack<T>::push(const T &item) {
  if (full())
    throw overflow();
  else
    stack_[top_++] = item;
}

template<typename T>
inline void 
stack<T>::push(T &&rval) {
  if (full())
    throw overflow();
  else
    emplace(std::forward<T>(rval));
}

template<typename T>
template<typename... Args>
inline void
stack<T>::emplace(Args &&... args) {
  if (full())
    throw overflow();
  else
    stack_[top_++] = std::move(T(std::forward<Args>(args) ...));
}

template<typename T>
inline void
stack<T>::pop() {
  if (empty())
    throw underflow();
  else
    --top_;
}

template<typename T>
inline const T &
stack<T>::top() const {
  if (empty())
    throw underflow();
  else
    return stack_[top_ - 1];
}

template<typename T>
inline T &
stack<T>::top() {
  if (empty())
    throw underflow();
  else
    return stack_[top_ - 1];
}

#endif /* _STACK_INL */

