#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>          
using namespace std;

/**
 * The STL set_union() algorithm constructs a sorted range beginning
 * in the location pointed by result with the set union of the two
 * sorted ranges [first1,last1) and * [first2,last2) as content.
 * 
 * The union of two sets is formed by the elements that are present in
 * either one of the sets, or in both.
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
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};
  vector<int> v;

  sort (begin(first), end(first));     
  sort (begin(second), end(second));   

  set_union (begin(first), end(first),
             begin(second), end(second),
             back_inserter(v));
 
  cout << "union has " << v.size() << " elements:\n";

  copy(v.begin(),
       v.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
