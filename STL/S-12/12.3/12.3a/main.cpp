#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The numeric algorithms are math functions found in <numeric>.
 * 
 * . accumulate() - Calculates the sum of all the elements in a
 *   specified range. It doesn't change the input data and can also
 *   concatenate strings. It can also give the product of the data in
 *   the range.
 * 
 * . adjacent_difference() - Calculates the successive differences
 *   between each data element and the one before it, given an input
 *   range.  It outputs the results to a destination range or performs
 *   any operation where the difference operation is replaced by another
 *   binary operation passed as an argument.
 *  
 * . inner_product() - Calculates the sum of the element-wise product
 *   of two ranges and adds it to a specified initial value or
 *   calculates the result of a generalized procedure where the sum and
 *   product binary operations are replaced by other specified binary
 *   operations.
 *  
 * . partial_sum() - Calculates a series of sums in an input range
 *   from the first element through the nth element and stores the
 *   result of each such sum in nth element of a destination range or
 *   it calculates the result of a generalized procedure where the sum
 *   operation is replaced by another specified binary operation.
 */

/**
 * Sum up only odd numbers.
 */
struct sum_odd {
  int operator() (int sum, int y) {
    return (y % 2) == 1 ? sum + y : sum; 
  }
};

/**
 * This program demonstrates the use of partial_sum() and accumulate()
 * to compute the sum of the odd numbers in the range 1 .. 10.
 */
int main() {
  vector<int> v(10, 1);
  
  partial_sum(v.begin(), v.end(), v.begin());
  
  for (auto i : v)
    cout << i << ' ';

  cout << "\nThe sum of all the odd numbers is "
	<< accumulate(v.begin(), v.end(), 0, sum_odd())
	<< endl;

  return 0;
}
