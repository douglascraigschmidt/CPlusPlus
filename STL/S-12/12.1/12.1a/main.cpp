#include <algorithm>
#include <set>
#include <iostream>
#include <iterator>          
using namespace std;

/**
 * STL defines a number of set algorithms:
 *
 * . set_union() - Computes the union of two sets
 * . set_intersection() - Computes the intersection of two sets
 * . set_difference() - Computes the difference of two sets
 * . set_symmetric_difference() - Computes the symmetric difference of
 *   two sets.
 *
 * These algorithms expect the ranges they work on are sorted.
 *
 * This example demonstrates how to apply the set_difference()
 * algorithm, which constructs a sorted range beginning in the
 * location pointed by result with the set difference of range
 * [first1,last1) with respect to [first2,last2) as content.
 *
 * The difference of two sets is formed by the elements that are
 * present in the first set, but not in the second one. Notice that
 * this is a directional operation - for a symmetrical equivalent, see
 * set_symmetric_difference.
 *
 * The comparison to check for equivalence of values uses either
 * operator< for the first version or comp for the second, in order
 * to test this; The value of an element, a, is equivalent to another
 * one, b, when (!a<b && !b<a) or (!comp(a,b) && !comp(b,a)).
 * 
 * For the set_difference() algorithm to yield the expected result,
 * the elements in the ranges shall be already ordered according to
 * the same strict weak ordering criterion (operator< or comp).
 */

/**
 * Forward declarations.
 */
static void set_difference_on_arrays();
static void set_difference_on_sets();

/**
 * This example shows how to compute set_difference() on built-in
 * arrays and on STL set containers.
 */
int main()  {
  set_difference_on_arrays();
  set_difference_on_sets();

  return 0;
}

static void 
set_difference_on_arrays() {
  int a1[] = {3, 1, 2, 5, 4, 7, 6, 9, 10, 8};
  int a2[] = {4, 2, 8, 12, 6, 10};
  int answer[distance(begin(a1), end(a1))];

  sort(begin(a1), end(a1));
  sort(begin(a2), end(a2));

  cout << "a1 = ";
  copy(begin(a1), end(a1), ostream_iterator<int>(cout," "));
  cout << "\na2 = ";
  copy(begin(a2), end(a2), ostream_iterator<int>(cout," "));

  // The difference of two sets is formed by the elements that are
  // present in the first set, but not in the second one.
  auto itr = set_difference(begin(a1), end(a1),
                            begin(a2), end(a2), 
                            begin(answer));

  cout << "\nThe set difference has " << distance(begin(answer), itr)
       << " elements with results = ";
  copy(begin(answer), itr, ostream_iterator<int>(cout," "));
  cout << endl;
}

static void 
set_difference_on_sets() {
  set<int> s1{3, 1, 2, 5, 4, 7, 6, 9, 10, 8};
  set<int> s2{4, 2, 8, 12, 6, 10};
  set<int> answer;

  cout << "s1 = ";
  copy(begin(s1), end(s1),
       ostream_iterator<int>(cout," "));
  cout << "\ns2 = ";

  copy(begin(s2), end(s2),
       ostream_iterator<int>(cout," "));

  auto itr = set_difference(begin(s1), end(s1),
                            begin(s2), end(s2),
                            inserter(answer, answer.end()));

    cout << "\nThe set difference has " << distance(begin(answer), end(answer))
         << " elements with results = ";
    copy(answer.begin(), answer.end(),
       ostream_iterator<int>(cout," "));
  cout << endl;
}
