#include <iostream>
#include <iterator>
#include <list>
using namespace std;

/**
 * This example shows how a front_inserter() causes the container's
 * push_front() operator to be invoked. This inserter can be used only
 * with the list and deque containers, because one cannot add to the
 * front of a vector.
 */
int main() {
  list<int> aList1, aList2;
  list<int>::iterator itr;
  int i;

  for(i = 0; i <5; i++)
    aList1.push_back(i);

  cout << "Original contents of aList:\n";
  copy (aList1.begin (),
        aList1.end (),
        ostream_iterator<int> (cout, "\n"));  

  front_insert_iterator<list<int> > frnt_i_itr(aList1);  
  // create a front_insert_iterator to aList

  *frnt_i_itr++ = 100;   // insert rather than overwrite at front
  *frnt_i_itr++ = 200;

  cout << "aList after insertion:\n";
  copy (aList1.begin (),
        aList1.end (),
        ostream_iterator<int> (cout, "\n"));  

  cout << "Size of aList2 before copy: " << aList2.size() << endl;

  copy(aList1.begin(),
       aList1.end(),
       front_inserter(aList2));

  cout << "Size of aList2 after copy: " << aList2.size() << endl;

  cout << "Contents of aList2 after insertion: ";
  copy (aList2.begin (),
        aList2.end (),
        ostream_iterator<int> (cout, "\n"));  

  return 0;
}
