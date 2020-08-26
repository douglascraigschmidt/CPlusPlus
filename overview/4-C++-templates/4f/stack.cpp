#ifndef _STACK_CPP
#define _STACK_CPP

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container>::stack(size_t size)
  : size_(size),
    stack_(size) {}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container>::stack(const stack<T, sequential_container> &rhs)
  : size_(rhs.size_),
    stack_(rhs.stack_) {
}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container>::stack(stack &&rhs) noexcept
  : size_(std::move(rhs.size_)),
    stack_(std::move(rhs.stack_)) {
}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container> &
stack<T, sequential_container>::operator=(const stack<T, sequential_container> &rhs) {
  if (this != &rhs) {
    stack<T, sequential_container>(rhs).swap(*this);
  }
  return *this;
}

template<typename T, template <typename ...> class sequential_container>
stack<T, sequential_container> &
stack<T, sequential_container>::operator=(stack<T, sequential_container> &&rhs)  noexcept {
  if (this != &rhs) {
    size_ = std::move(rhs.size_);
    stack_ = std::move(rhs.stack_);
  }
  return *this;
}

#endif /* _STACK_CPP */

