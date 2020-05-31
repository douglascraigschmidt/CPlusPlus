#include <iostream>
#include <memory>
#include <stdexcept>

using namespace std;

struct throw_exception {
  throw_exception &operator=(const throw_exception &rhs) {
    if (++i_ == 10) {
        throw std::out_of_range("index out of range");
    }
    return *this;
  }

  static int i_;
};

int throw_exception::i_ = 0;

template <typename T>
class Array
{
public:
  explicit Array(size_t size)
    : size_ (size),
      array_ (new T[size]) {
  }

  // No-op!
  ~Array() = default;

  Array(const Array<T> &rhs) // strong exception guarantees
    : size_ (rhs.size_),
      array_ (new T[rhs.size_]) {
    for (int i = 0;
         i < rhs.size_;
         ++i)
      // If T.operator=() throws exception we can handle it cleanly
      // since array_'s destructor deletes the memory.
      array_[i] = rhs.array_[i];

    /*
    // STL programmers would to this:
    std::copy(rhs.array_.get(),
            rhs.array_.get() + rhs.size_,
            array_.get()); */
  }

  Array<T> &operator= (const Array<T> &rhs) {
    if (this != &rhs) { // Check for self-assignment
      // Copy constructor and swap().
      Array<T>(rhs).swap(*this);
    }

    return *this;
  }

  void swap (Array<T> &rhs) noexcept { // no throw
    std::swap (rhs.size_, this->size_);
    rhs.array_.swap(this->array_);
  }

private:
  size_t size_;
  
  // replaced char * or T * with
  std::unique_ptr<T[]> array_;
};

int main() {
  try {
    Array<throw_exception> a1(1000);
    Array<throw_exception> a2(10);
    Array<throw_exception> a3(a1); // Copy constructor.

    a2 = a1; // Assignment operator.
    a1 = a2;
  } catch (std::out_of_range &range_error) {
    cout << "caught range error" << endl;
  }

  return 0;
}
