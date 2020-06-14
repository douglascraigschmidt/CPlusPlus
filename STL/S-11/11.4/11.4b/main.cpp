#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * The remove_if() algorithm removes from the range [first,last) the
 * elements for which pred applied to its value is true, and returns
 * an iterator to the new end of the range, which now includes only
 * the values for which pred was false.  Here's an example of
 * remove_if().
 */

bool is_odd (int i) { 
  return (i % 2) == 1; 
}

struct is_even {
  bool operator () (int i) { 
    return (i % 2) == 0;
  }
};

int main () {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto pend = remove_if (pbegin, pend, is_odd);

  cout << "with all odd values removed the range contains:";
  copy (begin(a), pend, ostream_iterator<int> (cout, " "));
  cout << endl;

  pend = remove_if (begin(a), pend, is_even_odder ());

  cout << "with all even values removed the range contains:";
  copy (begin(a), pend, ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
} 
