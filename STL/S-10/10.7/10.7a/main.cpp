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
 * • search: look in first range for an occurrence of the second
 *   range, possibly using a binary_predicate.
 * 
 * • search_n: look in range for an occurrence of n items equal to a
 *   value, possibly using a binary_predicate.
 */

/**
 * Forward declarations.
 */
template<typename InputIterator1, typename InputIterator2>
static void
search_for_subsequence(InputIterator1 first1, InputIterator1 last1,
                       InputIterator2 first2, InputIterator2 last2);
template <typename ForwardIterator, typename Size, typename T, typename BinaryPredicate>
static void
search_n_for_value(ForwardIterator first, ForwardIterator last,
                   Size size, const T &value,
                   BinaryPredicate pred);
template <typename Container, typename Predicate>
static void
adjacent_find_for_pred(const Container &container,
                       Predicate pred);

/**
 * This example demonstrates how to use the STL search() and
 * search_n() algorithms.  We also compare search_n() with the STL
 * adjacent_find() algorithm.
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

  // Search for subsequences using search().
  search_for_subsequence(l1.begin(), l1.end(), l3, l3 + 3);
  search_for_subsequence(l2.begin(), l2.end(), l3, l3 + 3);

  // Search for 2 consecutive values using search_n().
  search_n_for_value(l1.begin(), l1.end(), 2, "t",
                     [](const string &s, const string &v) {
                       return s[0] == v[0];
                     });
  search_n_for_value(l2.begin(), l2.end(), 2, "s",
                     [](const string &s, const string &v) {
                       return s[0] == v[0];
                     });

  // Search for 2 consecutive values using adjacent_find().
    adjacent_find_for_pred(l1,
                           [](const string &s, const string &v) {
                               return s[0] == v[0];
                           });
    adjacent_find_for_pred(l2,
                           [](const string &s, const string &v) {
                               return s[0] == v[0];
                           });
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
 * Use search_n() to search for a value in a sequence appearing n
 * times consecutively.
 */
template <typename ForwardIterator, typename Size, typename T, typename BinaryPredicate>
static void
search_n_for_value(ForwardIterator first, ForwardIterator last,
                   Size size, const T &value,
                   BinaryPredicate pred) {
  std::cout << __FUNCTION__ << "()\n";

  for (ForwardIterator tmp = first;
       tmp != last; ) {
    auto itr = search_n(tmp, last, size, value, pred);

    // Check if iterator itr found a match.
    if (itr != last) {
      cout << size << " values of "
           << value << " found at position " << distance(first, itr) << endl;
      tmp = ++itr;
    } else {
      if (tmp == first)
        cout << "consecutive values not present" << endl;
      break;
    }
  }
}

/**
 * Use adjacent_find() to search for a predicate in a sequence
 * appearing consecutively.
 */
template <typename Container, typename Predicate>
static void
adjacent_find_for_pred(const Container &container,
                       Predicate pred) {
  std::cout << __FUNCTION__ << "()\n";

  for (auto tmp = container.begin();
       tmp != container.end(); ) {
    auto itr = adjacent_find(tmp, container.end(), pred);

    // Check if iterator itr found a match.
    if (itr != container.end()) {
      cout << "2 values of "
           << (*itr)[0] << " found at position "
           << distance(container.begin(), itr) << endl;
      tmp = ++itr;
    } else {
      if (tmp == container.begin())
        cout << "2 consecutive values not present" << endl;
      break;
    }
  }
}
