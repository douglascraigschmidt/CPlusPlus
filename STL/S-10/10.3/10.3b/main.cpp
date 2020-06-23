#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-bind"
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <algorithm>
#include <iostream>
#include <deque>
#include <functional>
#include <memory>
#include <span>

using namespace std;

/**
 * The following example shows the following STL non-mutating
 * algorithms that find elements in an iterator range:
 *
 * . find() - finds a specified value in a given range 
 * . find_if() - finds the first element for which a predicate is true
 * . find_if_not() - finds the first element for which a predicate is false
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
  const T &value;
};

/**
 * Forward declarations.
 */
static void find_with_deque();
static void find_with_array();

/**
 * Demonstrates algorithms from the find*() family using the
 * is_greater_than functor and alternative approaches using
 * bind()/greater<> and a C++ generic lambda function.
 */
int main() {
  find_with_deque();
  find_with_array();

  return 0;
}

static void
find_with_deque() {
  deque<int> values {10, 20, -30, 40, -50, 60, 20, -40};

  auto value = 20;

  // Use custom functor to find first value > 20.
  auto itr1 = find_if(values.begin(),
                      values.end(),
                      is_greater_than<int>(value));

  if (itr1 != values.end())
    cout << *itr1 << " is the first value greater than " << value << endl;


  value = 40;

  // Use C++ lambda function to first value that's *not* >= 40.
  itr1 = find_if_not(values.begin(),
                     values.end(),
                     [value](auto i) { return i >= value; });

  if (itr1 != values.end())
      cout << *itr1 << " is not greater than or equal to " << value << endl;

  // Use bind() and greater<> functor to find last value > 20.
  auto itr2 = find_if(values.rbegin(),
                      values.rend(),
                      bind (greater<>(), placeholders::_1, value));

  if (itr2 != values.rend())
    cout << *itr2 << " is the last value greater than " << value << endl;
}

static void
find_with_array() {
  const int size = 8;
  unique_ptr<int[]> v1 (new int[size]{10, 20, -30, 40, -50, 60, 20, -40});
  unique_ptr<int[]> v2 (new int[size]);

  span s (v1.get(), v1.get() + size);

  copy(s.begin(),
       s.end(),
       v2.get());

  auto value = 20;

  // Use custom functor to find first value > 20.
  auto itr1 = find_if(v1.get(),
                      v1.get() + size,
                      is_greater_than<int>(value));

  if (itr1 != v1.get() + size)
    cout << *itr1 << " is the first value greater than "
         << value << endl;

  // Use C++ lambda function to first value that's *not* >= 40.
  itr1 = find_if_not(v2.get(),
                     v2.get() + size,
                     [value](auto i) {
                       return i >= value;
                     });

  if (itr1 != v2.get() + size)
    cout << *itr1 << " is not greater than or equal to "
         << value << endl;

  value = 40;

  // Use bind() and greater<> functor to find last value > 20.
  auto itr2 = find_if(s.rbegin(),
                      s.rend(),
                      bind (greater<>(), placeholders::_1, value));

  if (itr2 != s.rend())
    cout << *itr2 << " is the last value greater than "
         << value << endl;
}

#pragma clang diagnostic pop
