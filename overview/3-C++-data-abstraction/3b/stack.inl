#ifndef _STACK_INL
#define _STACK_INL

inline bool
stack::empty() const {
  return top_ == 0;
}

inline bool
stack::full() const {
  return top_ == size_;
}

inline void
stack::push(const T &item) {
  stack_[top_++] = item;
}

inline void 
stack::push(T &&rval) {
  stack_[top_++] = std::move(rval);
}

inline const T &
stack::top() const {
  return stack_[top_ - 1];
}

inline T &
stack::top() {
  return stack_[top_ - 1];
}

inline void
stack::pop() {
  --top_;
}

#endif /* _STACK_INL */
