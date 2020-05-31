#include <set>
#include <iostream>
using namespace std;

/**
 * There is only one way to add a new element to a set or multiset
 * after initializing via the constructor; you insert a value using
 * the insert() member function.
 * 
 * The insert() methods for a set return a pair of values, where the
 * first field contains the iterator, and the second field contains a
 * boolean value that is true if the element was inserted, and false
 * otherwise. In a set, an element will not be inserted if it matches
 * an existing element.
 *
 * This example inserts a value in a set and shows what happens when
 * the same value is inserted again.
 */
int main() {
  set<int> firstSet;

  // Insert an element with value of 55
  firstSet.insert(55);

  // This call will fail since 55 is already a member of the set.
  if (firstSet.insert(55).second)
    cout << "element was inserted" << endl;
  else
    cout << "element was not reinserted " << endl;

  return 0;
}
