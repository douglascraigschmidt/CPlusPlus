#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

/* Type of Stack element. */
typedef int T;

/**
 * This stack implements the "rule of 3"
 * https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming).
 */
class stack {
public:
  enum { DEFAULT_SIZE = 20 };

  stack(size_t size = DEFAULT_SIZE);

  stack(const stack &rhs);

  stack &operator=(const stack &rhs);

  ~stack();

  void push(const T &item);

  const T &top() const;

  T &top();

  void pop();

  bool empty() const;

  bool full() const;

private:
  size_t top_;
  size_t size_;
  T *stack_;
};

#endif /* _STACK_H */
