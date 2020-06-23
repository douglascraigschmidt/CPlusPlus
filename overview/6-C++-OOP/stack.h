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
      [[nodiscard]] const char *what() const noexcept override {
        return "underflow exception happened";
      }
  };

  class overflow : public exception {
  public:
      [[nodiscard]] const char *what() const noexcept override {
        return "overflow exception happened";
      }
  };

  virtual ~stack() = default;

  virtual void push(const T &item) = 0;

  virtual void push(T &&rval) = 0;

  virtual const T &top() const = 0;

  virtual T &top() = 0;

  virtual void pop() = 0;

  [[nodiscard]] virtual bool empty() const = 0;

  [[nodiscard]] virtual bool full() const = 0;
};

#endif /* _STACK_H */
