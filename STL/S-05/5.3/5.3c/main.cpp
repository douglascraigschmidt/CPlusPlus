#include  <set>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;

/**
 * This example creates a few sets and uses swap().
 */
int main() {
  // Defaults to less<int>, so elements appear in ascending order.
  set<int> firstSet {5, 4, 6, 7, 8, 2, 1, 3};

  // Store a reference to the first set.
  const set<int> &secondSet = firstSet;

  // Copy the set into a list via an iterator range.
  list<int> aList (secondSet.begin (), secondSet.end ());

  // Create a new set that's arranged in descending order.
  set<int, greater<>> thirdSet (aList.begin(), aList.end());

  set<int> fourthSet;
  // Swap the contents of the first and forth sets.
  fourthSet.swap (firstSet);

  assert(firstSet.empty());

  copy (thirdSet.begin (),
        thirdSet.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  copy (fourthSet.begin (),
        fourthSet.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
}

