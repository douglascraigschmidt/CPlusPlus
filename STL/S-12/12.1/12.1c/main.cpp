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
 * either one of the sets or in both.
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
  vector<int> answer;

  sort (begin(a1), end(a1));
  sort (begin(a2), end(a2));

  // The union of two sets is formed by the elements that are present in
  // either one of the sets, or in both.
  set_union (begin(a1), end(a1),
             begin(a2), end(a2),
             back_inserter(answer));
 
  cout << "union has " << answer.size() << " elements:\n";

  copy(answer.begin(),
       answer.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}
