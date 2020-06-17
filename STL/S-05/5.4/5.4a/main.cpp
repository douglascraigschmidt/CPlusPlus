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
 * algorithms: set_union(), set_intersection(), set_difference(), and
 * set_symmetric_difference() because:
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
 * The following example of multiset uses several STL algorithms. The
 * copy() algorithm copies each element from the specified range
 * (given by its first two input iterator arguments) into a location
 * pointed to by the third argument output iterator argument.
*/
int main() {
  multiset<int> a {4, 1, 1, 1, 1, 1, 0, 5, 1, 0};
  multiset<int> b {4, 4, 2, 4, 2, 4, 0, 1, 5, 5};
  multiset<int> c;

  cout << "Set a: ";
  copy(a.begin(),
       a.end(),
       ostream_iterator<int>(cout, " ")); 
  cout << endl;

  cout << "Set b: ";
  copy(b.begin(),
       b.end(),
       ostream_iterator<int>(cout, " ")); 
  cout << endl;

  cout << "Union: ";
  // Find elements that are in set a, set b, or both sets a and b.
  set_union(a.begin(), a.end(),
            b.begin(), b.end(),
            ostream_iterator<int>(cout, " "));
  cout << endl;  
 
  cout << "Intersection: ";
  // Find elements that are in both set a and set b.
  set_intersection(a.begin(), a.end(),
                   b.begin(), b.end(),
                   ostream_iterator<int>(cout, " "));
  cout << endl;

  // Find elements in set a that are not in set b.
  set_difference(a.begin(), a.end(),
                 b.begin(), b.end(),
                 // essentially back_inserter(c)
                 inserter(c, c.end()));
  cout << "Set c (difference of set a and set b): ";

  copy(c.cbegin(),
       c.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
