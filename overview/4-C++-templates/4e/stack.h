#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
#include <memory>

template<typename T, size_t SIZE>
class stack {
public:
  typedef T value_type;

  stack();

  stack(const stack &rhs);

  stack &operator=(const stack &rhs);

  ~stack() = default;

  void push(const value_type &item);

  void push(value_type &&rval);

  template <typename ... Args>
  void emplace(Args&& ... args);

  const stack<T, SIZE>::value_type &top() const;

  stack<T, SIZE>::value_type &top();

  void pop();

  bool empty() const;

  bool full() const;

private:
  size_t top_;
  value_type stack_[SIZE];
};

#include "stack.inl"
#include "stack.cpp"

#endif /* _STACK_H */
