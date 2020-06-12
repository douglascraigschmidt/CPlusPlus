#ifndef _ATOMIC_OP_H
#define _ATOMIC_OP_H

#include <mutex>

template <typename TYPE>
class atomic_op {
public:
  /// Initialize @c impl_ to c.
  explicit atomic_op (TYPE c): impl_(c) {}

  /// Manage copying...
  atomic_op (const atomic_op<TYPE> &c): impl_(c.impl_) {}

  /// Atomically assign @a rhs to @c value_.
  atomic_op<TYPE> &operator= (atomic_op<TYPE> const &rhs) {
    std::lock_guard<std::mutex> lock(mutex_);
    impl_ = rhs.impl_;
    return *this;
  }

  /// Atomically pre-increment @c impl_.
  TYPE operator++ () {
    std::lock_guard<std::mutex> lock(mutex_);
    return ++impl_;
  }

  /// Atomically pre-decrement @c impl_.
  TYPE operator-- () {
    std::lock_guard<std::mutex> lock(mutex_);
    return --impl_;
  }

  /// Explicitly return @c impl_.
  explicit operator TYPE() const {
    std::lock_guard<std::mutex> lock(mutex_);
    return impl_;
  }

private:
  mutable std::mutex mutex_;

  /// Underlying atomic op implementation.
  TYPE impl_;
};

#endif /* _ATOMIC_OP_H */
