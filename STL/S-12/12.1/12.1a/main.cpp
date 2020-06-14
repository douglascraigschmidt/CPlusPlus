#include <algorithm>
#include <set>
#include <iostream>
#include <iterator>          
using namespace std;

/**
 * STL defines a number of set algorithms:
 *
 * . set_union() - 
 * . set_intersection() - 
 * . set_difference() - 
 * . set_symmetric_difference() - 
 *
 * These algorithms expect the ranges they work on are sorted.
 *
 * This example demonstrates how to compute set difference, which is
 * ...
 */
int main()  {

  set<int> s1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  set<int> s2{2, 4, 6, 8, 10, 12};

  cout << "s1 =";
  copy(s1.begin(), s1.end(), ostream_iterator<int>(cout," "));
  cout << "\ns2 =";
  copy(s2.begin(), s2.end(), ostream_iterator<int>(cout," "));

  set_difference(s1.cbegin(), s1.cend(),
                 s2.cbegin(), s2.cend(), 
                 inserter(answer, answer.begin()));

  cout << "\nThe set-difference of s1 and s2 =";
  copy(answer.begin(), answer.end(), ostream_iterator<int>(cout," "));
  cout << endl;
  return 0;
}
