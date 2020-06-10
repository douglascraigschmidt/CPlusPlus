#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <algorithm>
#include <iostream>
#include <deque>
#include <functional>
using namespace std;

/**
 * The following example shows the following STL non-mutating
 * algorithms that find elements in an iterator range:
 *
 * . find          Finds a specified value in a given range 
 * . find_if       Finds the first element for which a predicate is true
 * . find_if_not   Finds the first element for which a predicate is false
 */

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
 * Demonstrates algorithms from the find*() family using the
 * is_greater_than functor and alternative approaches using
 * bind()/greater<> and a C++ generic lambda function.
 */
int main() {
  deque<int> values {10, 20, -30, 40, -50, 60, 20, -40};

  auto value = 20;

  // Use custom functor to find first value > 20.
  auto itr1 = find_if(values.begin(),
                      values.end(),
                      is_greater_than<int>(value));

  if (itr1 != values.end())
    cout << *itr1 << " is the first value greater than " << value << endl;

  // Use bind() and greater<> functor to find last value > 20.
  auto itr2 = find_if(values.rbegin(),
                      values.rend(),
                      bind (greater<>(), placeholders::_1, value));

  if (itr2 != values.rend())
    cout << *itr2 << " is the last value greater than " << value << endl;

  value = 40;

  // Use C++ lambda function to first value that's *not* >= 40.
  itr1 = find_if_not(values.begin(),
                     values.end(),
                     [value](auto i) { return i >= value; });

  if (itr1 != values.end())
    cout << *itr1 << " is not greater than or equal to " << value << endl;

  return 0;
} 
 
#pragma clang diagnostic pop
