#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>          
using namespace std;

/**
 * The STL set_intersection() algorithm constructs a sorted range beginning
 * in the location pointed by result with the set intersection of the
 * two sorted ranges [first1,last1) and [first2,last2) as content.
 *  
 * The intersection of two sets is formed only by the elements that
 * are present in both sets at the same time.
 * 
 * The comparison to check for equivalence of values, uses either
 * operator< for the first version, or comp for the second, in order
 * to test this; The value of an element, a, is equivalent to another
 * one, b, when (!a<b && !b<a) or (!comp(a,b) && !comp(b,a)).
 * 
 * For the function to yield the expected result, the elements in the
 * ranges shall be already ordered according to the same strict weak
 * ordering criterion (operator< or comp).
 * 
 * This example demonstrates how to apply the set_union() algorithm.
 */

int main () {
  int a1[] = { 5, 10, 15, 20, 25};
  int a2[] = {50, 40, 30, 20, 10};
  int results[distance(begin(a1), end(a1))];

  sort (begin(a1), end(a1));
  sort (begin(a2), end(a2));

  // The intersection of two sets is formed only by the elements that
  // are present in both sets at the same time.
  auto itr = set_intersection (begin(a1), end(a1),
                               begin(a2), end(a2),
                               begin(results));

  cout << "intersection has " << distance(begin(results), itr)
       << " elements:\n";
  copy (begin(results), itr, ostream_iterator<int> (cout, " "));
  cout << endl;

  return 0;
}
