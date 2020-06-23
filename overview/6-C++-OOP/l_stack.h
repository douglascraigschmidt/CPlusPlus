#ifndef _L_STACK_H
#define _L_STACK_H

#include <list>

#include "stack.h"

template<typename T>
class l_stack : public stack<T> {
public:
  explicit l_stack(size_t size);

  void push(const T &item) override;

  void push(T &&rval) override;

  const T &top() const override;

  T &top() override;

  void pop() override;

  [[nodiscard]] bool empty() const override;

  [[nodiscard]] bool full() const override;

private:
  size_t size_;
  std::list<T> stack_;
};

#include "l_stack.cpp"

#endif /* _L_STACK_H */
