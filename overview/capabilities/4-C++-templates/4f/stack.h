#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
#include <memory>
#include <vector>

template<typename T, 
         template <typename ...> class sequential_container = std::vector>
class stack {
public:
  typedef T value_type;

  static const int DEFAULT_SIZE = 20;

  explicit stack(size_t size = DEFAULT_SIZE);

  stack(const stack<T, sequential_container> &rhs);

  stack(stack<T, sequential_container> &&rhs) noexcept;

  stack<T, sequential_container> &operator=(const stack<T, sequential_container> &rhs);

  stack<T, sequential_container> &operator=(stack<T, sequential_container> &&rhs) noexcept;

  ~stack() = default;

  void push(const value_type &item);

  void push(value_type &&rval);

  template <typename ... Args>
  void emplace(Args&& ... args);

  const T &top() const;

  T &top();

  void pop();

  bool empty() const;

  bool full() const;

  void swap(stack<T, sequential_container> &rhs) noexcept;

private:
  size_t size_;
  sequential_container<T> stack_;
};

#include "stack.inl"
#include "stack.cpp"

#endif /* _STACK_H */
