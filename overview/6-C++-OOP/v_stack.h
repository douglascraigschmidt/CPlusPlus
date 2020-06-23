#ifndef _V_STACK_H
#define _V_STACK_H

#include <vector>

#include "stack.h"

template<typename T>
class v_stack : public stack<T> {
public:
  explicit v_stack(size_t size);

  void push(const T &item) override;

  void push(T &&rval) override;

  const T &top() const override;

  T &top() override;

  void pop() override;

  [[nodiscard]] bool empty() const override;

  [[nodiscard]] bool full() const override;

private:
  size_t size_;
  std::vector<T> stack_;
};

#include "v_stack.cpp"

#endif /* _V_STACK_H */
