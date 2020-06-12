#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
#include <memory>

template<typename T>
class stack {
public:
  typedef T value_type;

  static const int DEFAULT_SIZE = 20;

  explicit stack(size_t size = DEFAULT_SIZE);

  stack(const stack<T> &rhs);

  stack(stack<T> &&rhs) noexcept;

  stack &operator=(const stack<T> &rhs);

  stack &operator=(stack<T> &&rhs) noexcept;

  ~stack();

  void push(const value_type &item);

  void push(value_type &&rval);

  template <typename ... Args>
  void emplace(Args&& ... args);

  const stack<T>::value_type &top() const;

  stack<T>::value_type &top();

  void pop();

  bool empty() const;

  bool full() const;

private:
  size_t top_;
  size_t size_;
  value_type *stack_;
};

#include "stack.inl"
#include "stack.cpp"

#endif /* _STACK_H */
