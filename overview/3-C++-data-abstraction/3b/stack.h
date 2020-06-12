#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

#include "simple_string.h"

/* Type of Stack element. */
typedef simple_string T;

/**
 * This stack implements the "rule of 5"
 * https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)#Rule_of_Five.
 * It also implements an optimization for push().
 */
class stack {
public:
  static const int DEFAULT_SIZE = 20;

  explicit stack(size_t size = DEFAULT_SIZE);

  stack(const stack &rhs);

  stack(stack &&rhs) noexcept;

  stack &operator=(const stack &rhs);

  stack &operator=(stack &&rhs) noexcept;

  ~stack();

  void push(const T &item);

  void push(T &&rval);

  const T& top() const;

  T &top();

  void pop();

  bool empty() const;

  bool full() const;

private:
  size_t top_;
  size_t size_;
  T *stack_;
};

#include "stack.inl"

#endif /* _STACK_H */
