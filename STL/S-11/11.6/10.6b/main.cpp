#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * Forward declaration.
 */
template<typename InputIterator1, typename InputIterator2>
static void
find_mismatches(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2);

/**
 * This example demonstrates how to use the STL equal() and mismatch()
 * algorithms (as well as STL the distance() algorithm) on various
 * types of "containers".
 */
int main()  {
  vector<int> v1 {10, 20, 30, 40, 50};
  vector<int> v2(v1);

  // Compare two vectors that will match perfectly.
  find_mismatches(v1.begin(), v1.end(), v2.begin(), v2.end());

  // Compare two different types of "containers" that won't match.
  int a[] = {10, 40, 60, 80, 100};

  find_mismatches(v1.begin(), v1.end(), begin(a), end(a));

  return 0;
}

template<typename InputIterator1, typename InputIterator2>
static void
find_mismatches(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2) {
  // First check to see if the elements are equal.
  if (distance(first1, last1) == distance(first2, last2)
      && equal(first1, last1, first2))
    cout << "ranges are equal" << endl;
  else {
    // using default comparison via operator==.
    auto results = mismatch(first1, last1, first2);

    std::cout << "First mismatching elements: " << *results.first;
    std::cout << " and " << *results.second << '\n';

    // using predicate comparison done via a generic lambda function.
    results = mismatch(++results.first, last1,
                       ++results.second,
                       [](auto i, auto j) {
                         return i == j;
                       });

    cout << "Second mismatching elements: " << *results.first;
    cout << " and " << *results.second << '\n';
  }
}
