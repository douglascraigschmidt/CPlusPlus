#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

/**
 * Multisets are just like regular sets except that they allow duplicate keys. 
 *
 * template <typename Key, 
 *           typename Compare = less<Key>,
 *           typename Allocator = allocator <T> >
 * class multiset { ... };
 * 
 * Characteristics of multiset
 * . Stores objects of type key in a sorted manner.
 * . Its value type, as well as its key type, is 'key.'
 * . Two or more elements may be identical. 
 *
 * Set and multiset are particularly well suited to the set-related
 * algorithms: set_union, set_intersection, set_difference, and
 * set_symmetric_difference because:
 * 
 * . Set algorithms require their arguments to be sorted ranges and
 *   the elements in set and multiset are sorted in ascending order.
 * 
 * . The output range of these algorithms is always sorted and
 *   inserting a sorted range into a set or multiset is a fast
 *   operation.
 * 
 * . Inserting a new element into a multiset or set does not
 *   invalidate iterators that point to existing elements; only
 *   iterators pointing to elements being erased are invalid.
 *
 * The following is an example of multiset using several STL
 * algorithms. The copy algorithm copies each element from the
 * specified range (given by its first two arguments), into a place
 * pointed to by the third argument.
*/
int main() {
  multiset<int> A({4, 1, 1, 1, 1, 1, 0, 5, 1, 0});
  multiset<int> B({4, 4, 2, 4, 2, 4, 0, 1, 5, 5});
  multiset<int> C;

  cout << "Set A: ";
  copy(A.begin(), A.end(),
       ostream_iterator<int>(cout, " ")); 
  cout << endl;
  
  cout << "Set B: ";
  copy(B.begin(), B.end(),
       ostream_iterator<int>(cout, " ")); 
  cout << endl;

  cout << "Union: ";
  set_union(A.begin(), A.end(),
            B.begin(), B.end(),
            ostream_iterator<int>(cout, " "));
  cout << endl;  
 
  cout << "Intersection: ";
  set_intersection(A.begin(), A.end(),
                   B.begin(), B.end(),
                   ostream_iterator<int>(cout, " "));
  cout << endl;  
  set_difference(A.begin(), A.end(),
                 B.begin(), B.end(),
                 // essentially back_inserter(C)
                 inserter(C, C.end()));
  cout << "Set C (difference of A and B): ";

  copy(C.begin(), C.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}
