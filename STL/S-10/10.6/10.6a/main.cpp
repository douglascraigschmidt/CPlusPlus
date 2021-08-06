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
class print : public unary_function<T, void> {
public:
  explicit print(ostream &out) : os_(out), i_ (0) {}

  void operator() (const T &x) {
    os_ << x << ' '; ++i_; 
  }

  int count () { 
    return i_; 
  }

private:
  ostream& os_;
  int i_;
};

/**
 * This example demonstrates how to use the STL for_each() algorithm.
 */
int main() {
  int a[] = {1, 4, 2, 8, 5, 7};

  print<int> fun = for_each(begin(a),
                            end(a),
                            print<int>(cout));

  cout << endl << fun.count() << " objects printed." << endl;

  auto total = 0;
  for_each(begin(a),
           end(a),
           [&total](auto j) {
             cout << j << ' ';
             total++;
           });

  cout << endl << total << " objects printed." << endl;

  print<int> p(cout);

  for (auto i : a)
    p(i);

  cout << endl << p.count() << " objects printed." << endl;

  return 0;
}
