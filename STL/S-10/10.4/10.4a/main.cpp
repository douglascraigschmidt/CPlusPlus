#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-bind"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

/**
 * The following example shows the following STL non-mutating
 * algorithms that count elements in an iterator range:
 *
 * • count() - scan range and count occurrence of a value. 
 * • count_if() - scan range and count times a predicate is true.
 */

/**
 * A functor that returns the absolute value of its parameter.
 */
template<typename T>
struct abs_value {
  T operator()(T f) {
    return std::abs(f);
  }
};

/**
 * Demonstrates the use of STL algorithms count() and count_if()
 * in conjunction with our abs_value functor.
 */
int main() {
  vector<int> v {10, 20, -30, 40, 10, -40, 60, -10};

  // Get an iterator to the first occurrence of the value 10.
  auto itr = find(v.begin(), v.end(), 10);

  // Count # of times 10 occurs in range.
  auto num = count(v.begin(), v.end(), *itr);
  cout << "Found " << num << " occurrences of " << *itr << endl;

  // Count # of times abs(10) occurs in range using nested binders.
  num = count_if(v.begin(),
                 v.end(),
                 bind(equal_to<>(),
                      bind(abs_value<int>(), placeholders::_1),
                      *itr));

  cout << "Found " << num << " occurrences of abs(" << *itr << ")" << endl;

  // Count # of times abs(10) occurs in range using a lambda function.
  num = count_if(v.begin(),
                 v.end(),
                 [itr](auto i) { return abs(i) == *itr; });

  cout << "Found " << num << " occurrences of abs(" << *itr << ")" << endl;

  return 0;
}

#pragma clang diagnostic pop
