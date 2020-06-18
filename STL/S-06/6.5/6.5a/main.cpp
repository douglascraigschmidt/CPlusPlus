#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

/**
 * Instead of extracting and inserting data explicitly from the passed
 * streams, we can use the stream adaptors to make the streams appear
 * as STL containers. Mutating algorithms like copy() can then manage the
 * process of building the container (which in our example below will
 * ultimately be sorted).  There are three stream adaptors: istream,
 * ostream, and stream buffers.
 *
 * Here is a function using both istream and ostream adaptors.
 */
int main () {
  list<string> my_list;

  copy(istream_iterator<string>(cin),
       istream_iterator<string>(),
       // Essentially back_inserter(), but more general.
       inserter(my_list, my_list.end()));

  // Sort the list.
  my_list.sort();

  copy(my_list.begin(),
       my_list.end(),
       ostream_iterator<string>(cout, "\n"));

  return 0;
}
