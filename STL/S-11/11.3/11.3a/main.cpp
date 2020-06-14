#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Some examples of non-mutating find algorithms:
 * 
 * • swap() - swaps values of two given variables. 
 * • iter_swap() - swaps two items in a container indicated by
 *   iterators. 
 * • swap_ranges() - interchanges value between two ranges. 
 * • reverse() - places the elements in the reverse order. 
 * • reverse_copy() - creates a backwards copy of a range.
 * • rotate() - given a middle point in a range, reorganizes range so
 *   that middle comes first. 
 * • rotate_copy() - creates a rotated copy. 
 *
 * This example uses the rotate() algorithm on a vector.
 */
int main () {
  vector<int> myVect{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "myVect originally contains:\n";
  copy (myVect.begin (),
        myVect.end (),
        ostream_iterator<int> (cout, " "));

  rotate(myVect.begin(),
         myVect.begin() + 5,
         myVect.end());

  cout << "\nmyVect rotated contains:\n";
  copy (myVect.begin (),
        myVect.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
}
