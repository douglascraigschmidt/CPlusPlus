#include <iostream>
#include <iterator>
#include <list>
using namespace std;

/**
 * This example shows how a front_inserter() causes the container's
 * push_front() operator to be invoked. This inserter can be used only
 * with the list and deque containers, because one cannot add to the
 * front of a vector.
 *
 * Here is the front_inserter() function template:
 *
 * template <typename Container>
 * front_insert_iterator<Container> front_inserter(Container& x) {
 *   return front_insert_iterator<Container>(x);
 * }
 * 
 * This function adapter leverages C++'s implicit type inference
 * feature for functions.
 */
int main() {
  list<int> aList1 {0, 1, 2, 3, 4}, aList2;

  cout << "Original contents of aList:\n";
  copy (aList1.begin (),
        aList1.end (),
        ostream_iterator<int> (cout, "\n"));  

  front_insert_iterator<list<int>> itr(aList1);
  // auto itr = aList1.begin();
  // create a front_insert_iterator to aList

  *itr++ = 100;   // insert rather than overwrite at front
  *itr++ = 200;

  cout << "aList after insertion:\n";
  copy (aList1.begin (),
        aList1.end (),
        ostream_iterator<int> (cout, "\n"));  

  cout << "Size of aList2 before copy: " << aList2.size() << endl;

  copy(aList1.begin(),
       aList1.end(),
       front_inserter(aList2));

  cout << "Size of aList2 after copy: " << aList2.size() << endl;

  cout << "Contents of aList2 after insertion: \n";
  copy (aList2.begin (),
        aList2.end (),
        ostream_iterator<int> (cout, "\n"));

  if (!equal(aList1.rbegin(), aList1.rend(), aList2.begin()))
      cout << "end of the world" << endl;
  else
      cout << "output is as expected" << endl;

  return 0;
}
