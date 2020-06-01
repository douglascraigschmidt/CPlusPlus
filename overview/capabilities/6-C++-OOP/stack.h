#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
#include <exception>
#include <memory>

using namespace std;

template<typename T>
class stack {
public:
  class underflow : public exception {
  public:
      const char *what() const noexcept override {
        return "underflow exception happened";
      }
  };

  class overflow : public exception {
  public:
      const char *what() const noexcept override {
        return "overflow exception happened";
      }
  };

  virtual ~stack() = default;

  virtual void push(const T &item) = 0;

  virtual void push(T &&rval) = 0;

  virtual template <typename ... Args>
  void emplace(Args&& ... args);

  virtual void top(T &item) const;

  virtual void pop();

  virtual bool empty() const;

  virtual bool full() const;
};

#include "stack.cpp"

#endif /* _STACK_H */
