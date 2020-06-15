#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Some examples of STL mutating algorithms:
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
 * This example uses the STL rotate() and rotate_copy() algorithms
 * on some vectors.
 */
int main () {
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};

  cout << "v1 originally contains:\n";
  copy (v1.begin (),
        v1.end (),
        ostream_iterator<int> (cout, " "));

  rotate(v1.begin(),
         v1.begin() + 4,
         v1.end());

  cout << "\nv1 rotated contains:\n";
  copy (v1.begin (),
        v1.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  vector<int> v2;

  rotate_copy(v1.begin(),
              v1.begin() + 5,
              v1.end(),
              back_inserter(v2));

  cout << "\nv2 rotated contains:\n";
  copy (v2.begin (),
        v2.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
}
