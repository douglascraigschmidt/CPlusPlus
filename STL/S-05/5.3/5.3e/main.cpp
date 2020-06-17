#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

/** 
 * The factory methods begin() and end() produce iterators for both
 * sets and multisets. The iterators produced by these functions are
 * constant so that keys cannot be changed when traversing the set
 * since this could perturb the ordering of the keys!!  There are also
 * reverse iterators: factory method rbegin() and rend() produce
 * iterators that yield the elements in reverse order.
 *
 * To remove a value from a set, use erase(). The arguments can be
 * either a specific value, an iterator that denotes a single value,
 * or a pair of iterators that denote a range of values.
 *
 * The example below demonstrates these various aspects of STL sets.
 */
int main() {
  set<int> firstSet {5, 4, 6, 7, 8, 2, 1, 3};

  // Print the elements of the set.
  copy (firstSet.begin (),
        firstSet.end (),
        ostream_iterator<int> (cout, " "));

  cout << endl;

  // Erase element whose value is 4.
  firstSet.erase(4);	

  auto five = firstSet.find(5);

  // Can't assign to const iterator!
  // *five = 100;

  // Erase element with value 5.
  firstSet.erase(five); 

  // Print the elements of the set.
  reverse_copy (firstSet.begin (),
                firstSet.end (),
                ostream_iterator<int> (cout, " "));

  cout << endl;

  // Erase all values in range 6 up to (but not including) 8, define 2
  // iterators.
  auto six = firstSet.find(6);
  auto eight = firstSet.find(8);
  firstSet.erase (six, eight);

  // Print the elements of the set in reverse order.
  copy (firstSet.rbegin (),
        firstSet.rend (),
        ostream_iterator<int> (cout, " "));

  cout << endl;

  return 0;
}

