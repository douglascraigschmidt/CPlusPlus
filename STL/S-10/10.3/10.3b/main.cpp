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
 * This functor stores state that's used in operator().
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
 * Demonstrate the is_creater_than functor and an alternative approach
 * using bind2nd() and greater<>.
 */
int main() {
  deque<int> values {10, 20, -30, 40, -50, 60};

  auto itr = find_if (values.begin(),
                      values.end(),
                      is_greater_than<int>(5));

  if (itr != values.end()) 
    cout << *itr << " is greater than 5" << endl;

  itr = find_if (values.begin(),
                 values.end(),
                 bind2nd (greater<int>(), 20));

  if (itr != values.end()) 
    cout << *itr << " is greater than 20" << endl;

  return 0;
} 
 

#pragma clang diagnostic pop