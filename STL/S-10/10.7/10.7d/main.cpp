#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Forward declarations.
 */
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last,
                      const T& value, Compare comp={});
template <typename InputIterator1, typename InputIterator2>
static void demonstrate_binary_find(InputIterator1 first1,
                                    InputIterator1 last1,
                                    InputIterator2 first2,
                                    InputIterator2 last2);
template <typename InputIterator1, typename InputIterator2>
static void demonstrate_binary_search(InputIterator1 first1,
                                      InputIterator1 last1,
                                      InputIterator2 first2,
                                      InputIterator2 last2);

/**
 * This example demonstrates how to use the STL binary_search() and
 * lower_bound() algorithms.
 */
int main() {
  string a[] = {"now", "is", "the", "time", 
                "for", "all", "good", "people",
                "to", "come", "to", "the", 
                "aid", "of", "their", "party"};

  string b[] = {"to", "find", "all", "good", "people"};

  sort(begin(a), end(a));

  demonstrate_binary_search(begin(a), end(a), begin(b), end(b));
  demonstrate_binary_find(begin(a), end(a), begin(b), end(b));

  return 0;
}

template <typename InputIterator1, typename InputIterator2>
static void
demonstrate_binary_search(InputIterator1 first1,
                          InputIterator1 last1,
                          InputIterator2 first2,
                          InputIterator2 last2) {
  for (; first2 != last2; ++first2) {
    std::cout << "Searching for " << *first2 << endl;
    if (binary_search(first1, last1, *first2)) {
      std::cout << "Found " << *first2 << endl;
    } else {
      std::cout << *first2 << " not found" << endl;
    }
  }
}

template <typename InputIterator1, typename InputIterator2>
static void
demonstrate_binary_find(InputIterator1 first1,
                        InputIterator1 last1,
                        InputIterator2 first2,
                        InputIterator2 last2) {
  auto i = 0;
  for (auto itr = first1; itr != last1; ++itr) {
      cout << "[" << i++ << "] = " << *itr << endl;

  for (; first2 != last2; ++first2) {
    std::cout << "Searching for " << *first2 << endl;

    auto it = binary_find(first1,
                          last1,
                          *first2);
    if (it != last1)
      std::cout << "Found " << *it << " at index " 
                << distance(first1, it) << endl;
    else
      std::cout << *first2 << " not found" << endl;
  }
}

/**
 * Simple wrapper for lower_range() that implements a more effective
 * binary search algorithm.
 */
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last,
                      const T& value, Compare comp={}) {
    first = std::lower_bound(first, last, value, comp);
    return first != last && !comp(value, *first) ? first : last;
}

