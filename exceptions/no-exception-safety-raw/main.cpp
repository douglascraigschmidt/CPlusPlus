#include <iostream>
#include <algorithm>

class Array
{
public:
    Array(int size)
            : size_ (size),
              array_ (new char[size])
    {
    }

    ~Array() {
        delete [] array_;
    }

    Array(const Array &rhs)
            : size_ (rhs.size_),
              array_ (new char[rhs.size_])
    {
        for (int i = 0;
             i < rhs.size_;
             ++i)
            array_[i] = rhs.array_[i];
    }

    Array &operator= (const Array &rhs)
    {
        if (this != &rhs) // Check for self-assignment.
        {
            char *temp = new char[rhs.size_];
            for (int i = 0;
                 i < rhs.size_;
                 ++i)
                temp[i] = rhs.array_[i];

            delete [] array_;
            array_ = temp;
        }

        return *this;
    }

private:
    int size_;
    char *array_;
};

int main()
{
    Array a1 (1000);
    Array a2 (10);
    Array a3 (a1); // Copy constructor.

    // ...

    a2 = a1; // Assignment operator.
    a1 = a2;

    return 0;
    // C++ will call the destructors for all the Array objects.
}