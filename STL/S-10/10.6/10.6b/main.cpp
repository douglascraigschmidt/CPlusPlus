#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>

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
 * algorithms (as well as the STL distance() algorithm) on various
 * types of sequential containers, as well as built-in arrays.
 */
int main()  {
  vector<int> v1 {10, 20, 30, 40, 50};
  deque<int> d1(v1.begin(), v1.end());

  // Compare two containers that will match perfectly.
  find_mismatches(v1.begin(), v1.end(), d1.begin(), d1.end());

  // Compare two different types of "containers" that won't match.
  int a[] = {10, 40, 60, 80, 50};

  find_mismatches(v1.begin(), v1.end(), begin(a), end(a));

  return 0;
}

template<typename InputIterator1, typename InputIterator2>
static void
find_mismatches(InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2, InputIterator2 last2) {
  std::cout << __FUNCTION__ << "()\n";

  // First check to see if the elements are equal.
  if (distance(first1, last1) == distance(first2, last2)) {
    if (equal(first1, last1, first2))
      cout << "ranges are equal" << endl;
    else {
      auto t1 = first1;
      auto t2 = first2;

      while (t1 != last1) {
        // using default comparison via operator==.
        auto results = mismatch(t1, last1, t2);

        if (results.first != last1) {
          std::cout << "mismatching elements: " << *results.first;
          std::cout << " and " << *results.second << '\n';

          t1 = ++results.first;
          t2 = ++results.second;
        } else
          t1 = last1;
      }
    }
  }
}
