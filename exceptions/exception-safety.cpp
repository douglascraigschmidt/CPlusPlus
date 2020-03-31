// -std=c++0x
#include <iostream>
#include <algorithm>
#include <memory>

template <typename T>
class Array
{
public:
  Array(int size)
    : size_ (size),
      array_ (new T[size])
  {
  }

  ~Array() {
  }

  Array(const Array<T> &rhs) // strong exception guarantees
    : size_ (rhs.size_),
      array_ (new T[rhs.size_])
  {
    for (int i = 0;
         i < rhs.size_;
         ++i)
      // If T.operator=() throws exception we can handle it cleanly
      // since array_'s destructor deletes the memory.
      array_.get()[i] = rhs.array_.get()[i];
  }

  Array &operator= (const Array<T> &rhs)
  {
    if (this != &rhs) // Check for self-assignment
      {
        // Copy constructor.
        Array<T> temp(rhs);
        swap(temp);
      }

    return *this;
  }

  void swap (Array<T> &array) // no throw
  {
    std::swap (array.size_, this->size_);
    array.array_.swap(this->array_);
  }

private:
  int size_;
  std::unique_ptr<T> array_;
};

int main()
{
  Array<int> a1 (10000000000);
  Array<int> a2 (10);
  Array<int> a3 (a1); // Copy constructor.

  // ...

  a2 = a1; // Assignment operator.
  a1 = a2; 

  return 0;
}
