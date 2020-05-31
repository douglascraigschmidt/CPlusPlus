#ifndef _STACK_H
#define _STACK_H

#include <cstddef>

/* Type of Stack element. */
typedef int T;

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

  void top(T &item) const;

  void pop();

  bool is_empty() const;

  bool is_full() const;

private:
  size_t top_;
  size_t size_;
  T *stack_;
};

#endif /* _STACK_H */
