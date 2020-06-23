#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>

using namespace std;

/**
 * STL algorithms include a number of functions that search for
 * elements in an iterator range, including the following:
 * 
 * . search() - look in first range for an occurrence of the second
 *   range, possibly using a binary_predicate.
 * 
 * . find_end() - Searches for the last occurrence of the sequence
 *   [s_first, s_last) in the range [first, last).

 * . search_n() - look in range for an occurrence of n items equal to a
 *   value, possibly using a binary_predicate.
 * 
 * . adjacent_find() - looks for first pair in range that are equal,
 *   or match under a binary_predicate.
 *
 * . binary_search() - Returns true if any element in the range
 *   [first,last) is equivalent to a value or a predicate and false
 *   otherwise.
 * 
 * . lower_bound() - Returns an iterator pointing to the first element
 *   in the range [first, last) that is not less than (i.e. greater or
 *   equal to) value, or last if no such element is found.
 */

/**
 * Forward declaration.
 */
template<typename InputIterator1, typename InputIterator2>
static void
search_for_subsequence(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2);
template<typename InputIterator1, typename InputIterator2>
static void
find_end_for_subsequence(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2);

/**
 * This example demonstrates how to use the STL search() and find_end() algorithms,
 * which are surprisingly similar!
 */
int main() {
  vector<string> l1 {"now", "is", "the", "time", 
                     "for", "all", "good", "people",
                     "to", "come", "to", "the", 
                     "aid", "of", "their", "party"};

  list<string> l2 {"I've", "seen", "all", "good", 
                   "people", "turn", "their", "heads",
                   "each", "day", "so", "satisfied", 
                   "I'm", "on", "my", "way"};

  string l3[] = {"all", "good", "people"};
  string l4[] = {"to"};

  // Search for subsequences using search().
  search_for_subsequence(l1.begin(), l1.end(), begin(l3), end(l3));
  search_for_subsequence(l2.begin(), l2.end(), begin(l3), end(l3));
  find_end_for_subsequence(l1.begin(), l1.end(), begin(l4), end(l4));

  return 0;
}

/**
 * Use search() to search for a subsequence in a sequence.
 */
template<typename InputIterator1, typename InputIterator2>
static void
search_for_subsequence(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2) {
  std::cout << __FUNCTION__ << "()\n";

  auto itr = search(first1, last1, first2, last2);
  
  // Check if iterator itr found a match.
  if (itr != last1) {
    cout << "subsequence is present at index " << distance(first1, itr) << endl;
  } else { 
    cout << "subsequence is not present" << endl;
  } 
}

/**
 * Use search() to search for a subsequence in a sequence.
 */
template<typename InputIterator1, typename InputIterator2>
static void
find_end_for_subsequence(InputIterator1 first1, InputIterator1 last1,
                         InputIterator2 first2, InputIterator2 last2) {
    std::cout << __FUNCTION__ << "()\n";

    auto itr = find_end(first1,
                        last1,
                        first2,
                        last2);

    if (itr != last1) {
        cout << "last occurrence is at index "
             << distance(first1, itr)
             << " with contents ";
        copy(itr,
             itr + distance(first2, last2),
             ostream_iterator<decltype(*last2)>(cout, " "));
        cout << endl;
    }
}
