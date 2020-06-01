#include <algorithm>  			// for copy algorithm
#include <iostream>   			// for cin, cout, endl
#include <iterator>   			// for stream_iterators and inserter
#include <vector>     			// for vector
#include <numeric>    			// for accumulate algorithm
using namespace std; 

int main () {
  typedef vector<int> Vector;

  typedef istream_iterator<Vector::value_type> is_iter;
  typedef ostream_iterator<Vector::value_type> os_iter;

  Vector v;
  Vector::value_type sum = 0;

  // Default constructor to get ending iterator; get values from cin
  // until EOF
  cout << "Enter a sequence of integers (eof to quit): ";
  copy (is_iter (cin),
        is_iter (),
        back_inserter (v));

  // Stream the whole vector and the sum to cout.
  copy (v.begin (),
        v.end () - 1,
        os_iter (std::cout, " + "));

  if (v.size () != 0)
    cout << v.back () 
         << " = "  
         << accumulate (v.begin (), v.end (), sum)
         << endl;
  return 0;
}
