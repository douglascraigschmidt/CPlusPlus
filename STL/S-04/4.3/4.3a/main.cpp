#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/**
 * An input iterator is the simplest type of iterator, because it can only
 * read forward in a sequence or collection of elements. It reads the
 * elements only once and can return the elements when it finds
 * them. One can dereference an input iterator to obtain the value it
 * points to, but one can't assign a new value to the element using
 * the iterator's functions.  Input iterators can only do these
 * operations:
 *
 * . construct themselves         i(j);
 * . assignment operator          i=j;
 * . equality/inequality operator i==j; i!=j;
 * . dereference operator         *j; j->m; // Can't write, but can read
 * . pre/post increment operator  ++j; j++; *j++;
 *
 * Input iterators are used by non-mutating algorithms. For example,
 * the STL find(), find_if(), and count() algorithms require no more
 * than input iterators as their first two arguments. One can pass
 * them more powerful iterators or pointers, but only the simplest
 * input iterators are required.
 *
 * The find() and find_if() algorithms also return only an input
 * iterator pointing to the element that matches the value to be
 * found, or if the value was not found, an iterator pointing beyond
 * the last element of the container.
 *
 * The example below uses an input iterator to read ints from standard
 * input and store them into a vector.
 */
int main () {
  // An initially empty vector.
  vector<int> v;

  /*
  // copy contents of cin as "int" and store at
  // the end of vector v.
  for (istream_iterator<int> i (cin);
       i != istream_iterator<int> ();
       ++i)
    // Add int to the end of the vector.
    v.push_back (*i);
    */

    // Use STL copy() algorithm along with
    // back_inserter()!
    copy (istream_iterator<int> (cin),
          istream_iterator<int>(),
          back_inserter(v));
}





