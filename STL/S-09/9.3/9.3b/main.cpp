#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * An overly specific functor!
 */
struct IntGreaterThanThree : public unary_function<int, bool> {
  bool operator() (int x) const { return x > 3; }
};

/**
 * Forward declaration. 
 */
template<typename InputIterator>
static void print_results(InputIterator first, InputIterator last);

/** 
 * This example shows functors being used with various combinations
 * the not1() and not2() negators, the find_if()/find_if_not() algorithms,
 * and a lambda function.
 */
int main() {
  vector<int> v{4, 1, 2, 8, 5, 7};

  // Use a custom functor and a negator to get an iterator to the
  // first element in the vector that's not greater than three.
  auto itr = find_if (v.begin(),
                      v.end(),
                      not1(IntGreaterThanThree()));

  print_results(itr, v.end());

  // Use an STL functor and a negator to get an iterator to the first
  // element in the vector that's not greater than three.
  itr = find_if (v.begin(),
                 v.end(),
                 not1(bind2nd(greater<int> (), 3)));

  print_results(itr, v.end());

  // Use an STL lambda function to get an iterator to the first
  // element in the vector that's not greater than three.
  itr = find_if_not (v.begin(),
                     v.end(),
                     [](int i) { return i > 3; });

  print_results(itr, v.end());

  // Sort the vector using "not" less (i.e., greater).
  sort(v.begin(),
       v.end(),
       not2(less<int>()));

  print_results(v.begin(), v.end());

  return 0;
}

/**
 * Print the range
 */
template <typename InputIterator>
static void
print_results(InputIterator first, InputIterator last) {
  if (first != last) {
    copy (first,
          last,
          // Deduce the type of the iterator!
          ostream_iterator<decltype(*first)> (cout, " "));
    cout << endl;
  }
}
