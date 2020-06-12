#ifndef _STACK_H
#define _STACK_H

#include <cstddef>
#include <exception>
#include <memory>

using namespace std;

template<typename T>
class stack {
public:
  static const int DEFAULT_SIZE = 20;

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

  explicit stack(size_t size = DEFAULT_SIZE);

  stack(const stack &rhs);

  stack(stack &&rhs) noexcept;

  stack &operator=(const stack &rhs);

  stack &operator=(stack &&rhs) noexcept;

  ~stack() = default;

  void push(const T &item);

  void push(T &&rval);

  template <typename ... Args>
  void emplace(Args&& ... args);

  const T &top() const;

  T &top();

  void pop();

  bool empty() const;

  bool full() const;

  void swap(stack &rhs) noexcept;

private:
  size_t top_;
  size_t size_;
  std::unique_ptr<T[]> stack_;
};

#include "stack.inl"
#include "stack.cpp"

#endif /* _STACK_H */
