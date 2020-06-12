#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Simple wrapper for lower_range().
 */
template<class ForwardIt, class T, class Compare=std::less<>>
ForwardIt binary_find(ForwardIt first, ForwardIt last,
                      const T& value, Compare comp={}) {
    first = std::lower_bound(first, last, value, comp);
    return first != last && !comp(value, *first) ? first : last;
}

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

  for (auto &word : b) {
    std::cout << "Searching for " << word << endl;
    if (binary_search(begin(a), end(a), word)) {
      std::cout << "Found " << word << endl;
    } else {
      std::cout << word << " not found" << endl;
    }
  }

  vector<string> c(begin(a), end(a));

  auto i = 0;
  for (const auto& s : c)
      cout << "[" << i++ << "] = " << s << endl;

  for (auto &word : b) {
    std::cout << "Searching for " << word << endl;

    auto it = binary_find(c.cbegin(),
                          c.cend(),
                          word);
    if (it != c.cend())
      std::cout << "Found " << word << " at index " 
                << distance(c.cbegin(), it) << endl;
    else
      std::cout << word << " not found" << endl;
  }

  return 0;
}
