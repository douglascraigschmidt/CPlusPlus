#ifndef _STACK_INL
#define _STACK_INL

template<typename T, size_t SIZE>
inline bool
stack<T, SIZE>::empty() const {
  return top_ == 0;
}

template<typename T, size_t SIZE>
inline bool
stack<T, SIZE>::full() const {
  return top_ == SIZE;
}

template<typename T, size_t SIZE>
inline void
stack<T, SIZE>::push(const value_type &item) {
  stack_[top_++] = item;
}

template<typename T, size_t SIZE>
inline void 
stack<T, SIZE>::push(T &&rval) {
  emplace(std::forward<T>(rval));
}

template<typename T, size_t SIZE>
template<typename... Args>
inline void
stack<T, SIZE>::emplace(Args &&... args) {
  stack_[top_++] = std::move(T(std::forward<Args>(args) ...));
}

template<typename T, size_t SIZE>
inline void
stack<T, SIZE>::pop() {
  --top_;
}

template<typename T, size_t SIZE>
inline const typename stack<T, SIZE>::value_type &
stack<T, SIZE>::top() const {
  return stack_[top_ - 1];
}

template<typename T, size_t SIZE>
inline typename stack<T, SIZE>::value_type &
stack<T, SIZE>::top() {
  return stack_[top_ - 1];
}

#endif /* _STACK_INL */

