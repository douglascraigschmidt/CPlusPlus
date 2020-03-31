#include <iostream>
#include <algorithm>

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
    delete [] array_;
  }

  Array(const Array<T> &rhs)
    : size_ (rhs.size_),
      array_ (new T[rhs.size_])
  {
    for (int i = 0;
         i < rhs.size_;
         ++i)
      // If T.operator=() throws exception, we've got problems singe
      // the destructor is not called and array_ will leak memory!
      array_[i] = rhs.array_[i];
  }

  Array &operator= (const Array<T> &rhs)
  {
    if (this != &rhs) // Check for self-assignment.
      {
        T *temp = new T[rhs.size_];
        for (int i = 0;
             i < rhs.size_;
             ++i)
          // If T.operator=() throws exception, we've got problems
          // singe the destructor is not called and temp will leak
          // memory!
          temp[i] = rhs.array_[i];

        array_ = temp;
      }

    return *this;
  }

private:
  int size_;
  T *array_;
};

int main()
{
  Array<int> a1 (1000);
  Array<int> a2 (10);
  Array<int> a3 (a1); // Copy constructor.

  // ...

  a2 = a1; // Assignment operator.
  a1 = a2; 


  return 0;
}
