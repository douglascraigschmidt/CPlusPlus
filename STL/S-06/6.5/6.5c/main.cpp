#include <iostream>
#include <iterator>
#include <numeric>
#include <deque>
using namespace std;

/** 
 * Another type of stream iterator, ostream iterator, writes values to
 * a standard output stream, therefore allowing STL algorithms to
 * write to output streams.  Ostream iterators change the assignment
 * of a new value to be an output operation using the << operator.
 * 
 * When created, an ostream iterator must be provided with the output
 * stream and optionally a character can be defined to separate the
 * values being passed into the output stream
 */
int main() {
  ostream_iterator<int> oi(cout, " ");
  *oi++ = 6;
  *oi++ = 88;

  cout << endl;

  deque<int> d{3, 4, 7, 8};

  // Stream the whole deque and a sum to cout
  copy(d.begin(),
       d.end() - 1,
       ostream_iterator<int>(cout, " + "));

  cout << *(d.end() - 1)
       << " = "
       << accumulate(d.begin(), d.end(), 0)
       << endl;

  return 0;
}
