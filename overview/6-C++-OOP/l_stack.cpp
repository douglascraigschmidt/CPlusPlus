#ifndef _L_STACK_CPP
#define _L_STACK_CPP

#include <cstddef>
#include <exception>

template<typename T>
l_stack<T>::l_stack(size_t size)
  : size_ (size),
    stack_(0) {
}

template<typename T>
void 
l_stack<T>::push(const T &item) {
  if (full())
    throw typename stack<T>::overflow();
  else
    stack_.push_back(item);
}

template<typename T>
void 
l_stack<T>::push(T &&rval) {
  if (full())
    throw typename stack<T>::overflow();
  else
    stack_.push_back(rval);
}

template<typename T>
const T &
l_stack<T>::top() const {
  if (empty())
    throw typename stack<T>::underflow();
  else
    return stack_.back();
}

template<typename T>
T &
l_stack<T>::top() {
  if (empty())
    throw typename stack<T>::underflow();
  else
    return stack_.back();
}

template<typename T>
void 
l_stack<T>::pop() {
  if (empty())
    throw typename stack<T>::underflow();
  else
    stack_.pop_back();
}

template<typename T>
bool
l_stack<T>::empty() const {
  return stack_.empty();
}

template<typename T>
bool 
l_stack<T>::full() const {
  return stack_.size() == size_;
}

#endif /* _L_STACK_CPP */
