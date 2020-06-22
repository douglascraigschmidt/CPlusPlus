#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

/**
 * Forward declaration. 
 */
template<typename InputIterator>
static void print_results(InputIterator first, InputIterator last);

/**
 * An overly specific functor!
 */
struct IntGreaterThanThree : public unary_function<int, bool> {
  bool operator() (int x) const { return x > 3; }
};

/** 
 * This example shows functors being used with the not1(), not2(), and
 * not_fn() negators, the find_if()/find_if_not() STL algorithms, and a
 * C++ generic lambda function.
 */
int main() {
  vector<int> v{4, 1, 2, 8, 5, 7};

  // Use a custom functor and not1() negator to get an iterator to
  // the first element in the vector that's not greater than three.
  auto itr = find_if (v.begin(),
                      v.end(),
                      not1(IntGreaterThanThree()));

  print_results(itr, v.end());

  /*
  // Use an STL functor and a negator to get an iterator to the first
  // element in the vector that's not greater than three.
  itr = find_if (v.begin(),
                 v.end(),
                 not1(bind2nd(greater<int> (), 3)));
                 */

  print_results(itr, v.end());

  // Use an STL functor and a negator to get an iterator to the first
  // element in the vector that's not greater than three.
  itr = find_if (v.begin(),
                 v.end(),
                 not_fn(bind(greater<> (), placeholders::_1, 3)));

  print_results(itr, v.end());

  // Use an STL lambda function to get an iterator to the first
  // element in the vector that's not greater than three.
  itr = find_if_not (v.begin(),
                     v.end(),
                     [](auto i) { return i > 3; });

  print_results(itr, v.end());

  // Sort the vector using "not" less (i.e., greater).
  sort(v.begin(),
       v.end(),
       not2(less<int>())); // can also use not_fn().

  print_results(v.begin(), v.end());

  return 0;
}

/**
 * Print the range from first to last.
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
