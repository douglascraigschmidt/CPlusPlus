#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/**
 * There are several STL algorithms that remove elements from a range.
 * 
 * • remove() - deletes items in a range that equal a given value. 
 * • remove_if() - deletes items in a range if a predicate is true. 
 * • remove_copy() - makes a copy of items in a range but not those
 *   with a given value. 
 * • remove_copy_if() - makes a copy of items in a range but not those
 *   where a predicate is true. 
 * 
 * The remove*() algorithms do not alter the elements past the new
 * end, which keep their old values and are still accessible, as shown
 * in the following example.
 */
int main () {
  int a[] = {10, 20, 30, 30, 20, 10, 10, 20};

  cout << "original array contains:";
  copy (begin(a), end(a), ostream_iterator<int> (cout, " "));
  cout << endl;

  auto nend = remove (begin(a), end(a), 20);

  cout << "range contains:";
  copy (begin(a), nend, ostream_iterator<int> (cout, " "));
  cout << endl;

  cout << "complete array contains:";
  copy (begin(a), end(a), ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
}
 
