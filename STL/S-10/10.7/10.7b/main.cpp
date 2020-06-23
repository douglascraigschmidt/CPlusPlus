#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>

using namespace std;

/**
 * Forward declaration.
 */
template <typename ForwardIterator, typename Size, typename T, typename BinaryPredicate>
static void
search_n_for_value(ForwardIterator first, ForwardIterator last,
                   Size size, const T &value,
                   BinaryPredicate pred);
/**
 * This example demonstrates how to use the STL search_n() algorithm.
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

  // Search for 2 consecutive values using search_n().
  search_n_for_value(l1.begin(), l1.end(), 2, "t",
                     [](const string &s, const string &v) {
                       return s[0] == v[0];
                     });

  search_n_for_value(l2.begin(), l2.end(), 2, "s",
                     [](const string &s, const string &v) {
                       return s[0] == v[0];
                     });

  return 0;
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

  for (auto tmp = first;
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
