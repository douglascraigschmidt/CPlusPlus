#include <algorithm>  			
#include <iostream>   			
#include <iterator>   			
#include <vector>     			
#include <numeric>    			
using namespace std; 

/**
 * The class template istream_iterator reads elements from an input
 * stream using operator >>(). A value of type T is retrieved and
 * stored when the iterator is constructed and each time operator++()
 * is called.
 *
 * The iterator is equal to the end-of-stream iterator value if the
 * end-of-file is reached. The constructor with no arguments can be
 * used to create an end-of-stream iterator. The only valid use of
 * this iterator is to compare to other iterators when checking for
 * end of file. Do not attempt to dereference the end-of-stream
 * iterator; it plays the same role as the past-the-end iterator of
 * the end() function of containers.
 * 
 * Since an istream_iterator is an input iterator, one cannot assign
 * to the value returned by dereferencing the iterator. This also
 * means that istream_iterators can only be used for single pass
 * algorithms.
*/
int main () {
  typedef vector<int> Vector;

  typedef istream_iterator<Vector::value_type> is_iter;
  typedef ostream_iterator<Vector::value_type> os_iter;

  Vector v;

  // Default constructor to get ending iterator; get values from cin
  // until EOF.
  cout << "Enter a sequence of integers (eof to quit): ";
  copy (is_iter(cin),
        is_iter(),
        back_inserter (v));

  // Stream the whole vector and the sum to cout.
  copy (v.begin (),
        v.end () - 1,
        os_iter (std::cout, " + "));

  if (!v.empty())
    cout << v.back () 
         << " = "  
         << accumulate (v.begin (), v.end (), 0)
         << endl;

  return 0;
}
