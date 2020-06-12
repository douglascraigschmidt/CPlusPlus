#ifndef _STACK_INL
#define _STACK_INL

template<typename T, template <typename ...> class sequential_container>
inline void
stack<T, sequential_container>::swap(stack<T, sequential_container> &rhs) noexcept {
  std::swap(size_, rhs.size_);
  stack_.swap(rhs.stack_);
}

template<typename T, template <typename ...> class sequential_container>
inline bool
stack<T, sequential_container>::empty() const {
  return stack_.empty();
}

template<typename T, template <typename ...> class sequential_container>
inline bool
stack<T, sequential_container>::full() const {
  return stack_.size() == size_;
}

template<typename T, template <typename ...> class sequential_container>
inline void
stack<T, sequential_container>::push(const value_type &item) {
  stack_.push_back(item);
}

template<typename T, template <typename ...> class sequential_container>
inline void 
stack<T, sequential_container>::push(T &&rval) {
  stack_.push_back(rval);
}

template<typename T, template <typename ...> class sequential_container>
template<typename... Args>
inline void
stack<T, sequential_container>::emplace(Args &&... args) {
  stack_.emplace_back(std::move(T(std::forward<Args>(args) ...)));
}

template<typename T, template <typename ...> class sequential_container>
inline void
stack<T, sequential_container>::pop() {
  stack_.pop_back();
}

template<typename T, template <typename ...> class sequential_container>
inline const typename stack<T, sequential_container>::value_type &
stack<T, sequential_container>::top() const {
  return stack_.back();
}

template<typename T, template <typename ...> class sequential_container>
inline typename stack<T, sequential_container>::value_type &
stack<T, sequential_container>::top() {
  return stack_.back();
}

#endif /* _STACK_INL */

