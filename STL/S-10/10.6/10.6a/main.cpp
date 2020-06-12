#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * STL algorithms include a number of functions that process and/or
 * compare elements in an iterator range, including the following:
 * 
 * • for_each() - Apply a function to every item in a range.
 *
 * • equal() - test if a range equals, element another parallel range,
 *   possibly using a binary_predicate
 * 
 * • mismatch() - search two parallel ranges and returns position of the
 *   first one that is unequal or doesn't satisfy a binary_predicate.
*/

/**
 * This functor records the number of times its operator() is called
 * and prints the value to the given ostream.
 */
template<typename T> 
struct print
  : public unary_function<T, void> {
  explicit print(ostream &out) : os_(out), i_ (0) {}

  void operator() (const T &x) {
    os_ << x << ' '; ++i_; 
  }

  int count () { 
    return i_; 
  }

  ostream& os_;
  int i_;
};

/**
 * This example demonstrates how to use the STL for_each() algorithm.
 */
int main()  {
  int a_begin[] = {1, 4, 2, 8, 5, 7};
  auto a_end = a_begin + sizeof(a_begin) / sizeof(*a_begin);

  print<int> fun = for_each(a_begin,
                            a_end,
                            print<int>(cout));

  cout << endl << fun.count() << " objects printed." << endl;

  return 0;
}
