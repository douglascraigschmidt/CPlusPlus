#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <cstring>
using namespace std;

/**
 * Forward declaration.
 */
template <typename InputIterator>
static void 
print(InputIterator first, InputIterator last, const string &s);

/**
 * The example demonstrates the use of a number of C++ function
 * adapters, including ptr_fun(), not1()/bind2nd(), not_fn()/bind(), as well
 * as C++ generic lambda functions and decltype().
 */
int main() {
  vector<const char *> aVect {"One", "Two", "Three", "Four", "Five"};

  print(aVect.begin(), aVect.end(), "Sequence contains: ");

#if 0
  // Using not1(), bind2nd(), and ptr_fun() adapters.
  auto itr = find_if(aVect.begin(),
                     aVect.end(),
                     not1(bind2nd(ptr_fun(strcmp), "Three")));

  print(itr, aVect.end(), "Found it: ");

#else
  // Using not_fn() and bind()
  auto itr = find_if(aVect.begin(),
                     aVect.end(),
                     not_fn(bind(strcmp, placeholders::_1, "Two")));
#endif

  print(itr, aVect.end(), "Found it: ");

  // Use a generic lambda function.
  itr = find_if(aVect.begin(),
                aVect.end(),
                [](auto s) { return !strcmp(s, "One"); });

  print(itr, aVect.end(), "Found it: ");

  return 0;
}

template <typename InputIterator>
static void 
print(InputIterator first, InputIterator last, const string &s) {
  if (first != last) {
    cout << s;
    copy (first,
          last,
          ostream_iterator<decltype(*first)> (cout, " "));
    cout << endl;
  }

}
