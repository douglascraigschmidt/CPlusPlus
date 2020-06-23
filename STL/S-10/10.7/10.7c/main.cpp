#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>

using namespace std;

/**
 * Forward declaration.
 */
template <typename Container, typename Predicate>
static void
adjacent_find_for_pred(const Container &container, Predicate pred);

/**
 * This example demonstrates how to use the STL adjacent_find()
 * algorithm.
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
