#ifndef _V_STACK_H
#define _V_STACK_H

#include <vector>

#include "stack.h"

template<typename T>
class v_stack : public stack<T> {
public:
  explicit v_stack(size_t size);

  virtual void push(const T &item);

  virtual void push(T &&rval);

  virtual const T &top() const;

  virtual T &top();

  virtual void pop();

  virtual bool empty() const;

  virtual bool full() const;

private:
  size_t size_;
  std::vector<T> stack_;
};

#include "v_stack.cpp"

#endif /* _V_STACK_H */
