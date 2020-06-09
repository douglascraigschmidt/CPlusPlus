#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <algorithm>
#include <iostream>
#include <deque>
#include <functional>
using namespace std;

/**
 * Define a is_greater_than functor that takes any type of numeric
 * data or even a class if the > operator has been defined for it.
 * This is a "stateful functor" since it stores state that's used in
 * operator().
 */
template <typename T>
class is_greater_than {
public:
  explicit is_greater_than (const T &n): value(n) {}

  bool operator() (const T &element) const {
      return element > value;
  }

private:
  const T value;
};

/**
 * Demonstrate the is_greater_than functor and an alternative approach
 * using bind2nd() and greater<>.
 */
int main() {
  deque<int> values {10, 20, -30, 40, -50, 60};

  auto value = 5;

  // Use custom functor to find first value > 5.
  auto itr = find_if (values.begin(),
                      values.end(),
                      is_greater_than<int>(value));

  if (itr != values.end()) 
    cout << *itr << " is greater than " << value << endl;

  value = 20;

  // Use bind() and greater<> functor to find first value > 20.
  itr = find_if (values.begin(),
                 values.end(),
                 bind (greater<int>(), placeholders::_1, value));

  if (itr != values.end()) 
    cout << *itr << " is greater than " << value << endl;

  value = 40;

  // Use C++ lambda function to first value >= 40.
  itr = find_if (values.begin(),
                 values.end(),
                 [value](auto i) { return i >= value; });

  if (itr != values.end()) 
    cout << *itr << " is greater than " << value << endl;

  return 0;
} 
 

#pragma clang diagnostic pop
