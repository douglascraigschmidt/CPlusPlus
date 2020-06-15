#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Output iterators are similar to input iterators, except that they
 * perform only write operations.  Output iterators also process a
 * container only in a single pass and do no error checking. So the
 * code itself needs to check that a value to be written is valid and
 * whether each write operation was successful. Output iterators can
 * do the following:
 *
 * . constructor                 i(j);
 * . assignment operator         i=j;
 * . dereference operator        *j=t; *j++=t; // Can write, but can't read!
 * . pre/post increment operator ++j; j++;
 *
 * Many STL algorithms (e.g., copy() and transform()) return an output
 * iterator as their result, which enables chaining of these operations.
 *
 * The example below uses an input iterator to read ints from standard
 * input and store them into a vector using an output iterator
 * adapter.  It then uses another output iterator adapter to write the
 * contents of vector to standard out.
 */
int main () {
  // An initially empty vector.
  vector<int> v;

  // Copy contents of cin as ints to the end of vector v.
  copy (istream_iterator<int>(cin),
        istream_iterator<int>(),
        back_inserter(v));

  // Copy contents of vector v to cout.
  copy (v.cbegin (),
        v.cend (),
        ostream_iterator<int> (cout, "\n"));
/*
    // The same behavior using various loops.
    for (auto i = v.begin ();
         i != v.end ();
         ++i)
      cout << *i << endl;

    for (auto i : v)
      cout << i << endl;
      */
}
