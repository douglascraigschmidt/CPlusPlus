#ifndef _STACK_INL
#define _STACK_INL

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
stack<T>::push(const value_type &item) {
  stack_[top_++] = item;
}

template<typename T>
template<typename... Args>
inline void
stack<T>::emplace(Args &&... args) {
  stack_[top_++] = std::move(T(std::forward<Args>(args) ...));
}

template<typename T>
inline void
stack<T>::pop() {
  --top_;
}

template<typename T>
inline const typename stack<T>::value_type &
stack<T>::top() const {
  return stack_[top_ - 1];
}

template<typename T>
inline typename stack<T>::value_type &
stack<T>::top() {
  return stack_[top_ - 1];
}

template<typename T>
inline void stack<T>::push(T &&rval) {
  emplace(std::forward<T>(rval));
}

#endif /* _STACK_INL */

