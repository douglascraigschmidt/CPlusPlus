#include <iostream>
#include <deque>
#include <iterator>
#include <algorithm>
using namespace std;

/**
 * Reverse iterators walk backwards through collections. There are two
 * types: reverse_iterator, which only goes backward through the data,
 * and reverse_bidirectional_iterator, which can go backward and
 * forward.
 *
 * Useful Operators
 * These iterators can be created using a default constructor or by a
 * single argument constructor which initializes the new
 * reverse_iterator with a random_access_iterator.  Here are some of
 * their operators:
 *
 * * operator 	        returns a reference to the current item i.e. value pointed to.
 *
 * ++ operator	        advances the iterator to the previous item
 *                      (--current) and returns a reference that item. 
 * 
 * ++ operator (int) 	advances the iterator to the integer previous item
 *                      (--current) and returns a copy of the previous item.
 *
 * -- operator 	        advances the iterator to the next item
 *                      (++current) and returns a reference to that item. 
 * 
 * -- operator (int)	advances the iterator to the integer next item
 *                      (++current) and returns a copy to the previous item. 
 * 
 * == operator    	This returns true only if the iterators x and
 *                      y point to the same item. 
 */
int main() {
  deque<int> aDeck;

  for (int i = 0;
       i <10;
       i++)
    aDeck.push_back(i);

  cout << "Contents printed backward:\n";

  copy (aDeck.rbegin (),
        aDeck.rend (),
        ostream_iterator<int> (cout, "\n"));

  cout << "Contents printed backwards with reverse iterator adapter:\n";

  reverse_iterator<deque<int>::iterator> rfirst(aDeck.end());
  reverse_iterator<deque<int>::iterator> rlast(aDeck.begin());

  copy (rfirst,
        rlast,
        ostream_iterator<int> (cout, "\n"));

  cout << "Contents printed backwards with reverse_copy:\n";
  reverse_copy (aDeck.begin (),
                aDeck.end (), 
                ostream_iterator<int> (cout, "\n"));

  return 0;
}
