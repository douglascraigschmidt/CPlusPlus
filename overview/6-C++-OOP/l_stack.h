#ifndef _L_STACK_H
#define _L_STACK_H

#include <list>

#include "stack.h"

template<typename T>
class l_stack : public stack<T> {
public:
  explicit l_stack(size_t size);

  virtual void push(const T &item);

  virtual void push(T &&rval);

  virtual const T &top() const;

  virtual T &top();

  virtual void pop();

  virtual bool empty() const;

  virtual bool full() const;

private:
  size_t size_;
  std::list<T> stack_;
};

#include "l_stack.cpp"

#endif /* _L_STACK_H */
