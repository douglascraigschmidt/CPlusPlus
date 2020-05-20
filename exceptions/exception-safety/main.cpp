#include <iostream>
#include <algorithm>
#include <memory>

template <typename T>
class Array
{
public:
  explicit Array(int size)
    : size_ (size),
      array_ (new T[size]) {
  }

  // No-op - can remove!
  ~Array() = default;

  Array(const Array<T> &rhs) noexcept // strong exception guarantees
    : size_ (rhs.size_),
      array_ (new T[rhs.size_]) {
    for (int i = 0;
         i < rhs.size_;
         ++i)
      // If T.operator=() throws exception we can handle it cleanly
      // since array_'s destructor deletes the memory.
      array_.get()[i] = rhs.array_.get()[i];

    // STL programmers would to this:
    // std::copy(rhs.array_.get(), rhs.array_.get() + rhs.size_, array_.get());
  }

  Array<T> &operator= (const Array<T> &rhs) noexcept { // strong exception guarantees
    if (this != &rhs) // Check for self-assignment
      {
        // Copy constructor.
        Array<T> temp(rhs);
        swap(temp);
      }

    return *this;
  }

  void swap (Array<T> &rhs) noexcept { // no throw
    std::swap (rhs.size_, this->size_);
    rhs.array_.swap(this->array_);
  }

private:
  int size_;
  // replaced char * or T * with
  std::unique_ptr<T> array_;
};

int main() {
    Array<int> a1 (100000000);
    Array<int> a2 (10);
    Array<int> a3 (a1); // Copy constructor.

    // ...

    a2 = a1; // Assignment operator.
    a1 = a2;

    return 0;
}
