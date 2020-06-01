#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/**
 * An inserter() causes the container's insert() operation to be
 * invoked. inserter() takes two arguments: the container and an
 * iterator into the container indicating the position at which
 * insertion should begin.
 *
 * One can construct an insert_iterator directly from a container and
 * an iterator i. The values written to the insert iterator are
 * inserted before i. inserters can be used in place of output
 * iterators.  Create one like this to insert elements at the back of
 * a deque:
 * 
 * deque<int> aDeck;
 * insert_iterator<deque<int> (aDeck, aDeck.end() );
 *
 * One can also declare back and front inserters like this using a deque:
 * 
 * deque<int> aDeck;
 * back_insert_iterator<deque<int>>	backItr (aDeck);
 * front_insert_iterator<deque<int>>	forwardItr (aDeck);
 *
 * Here is an example using an insert iterator for vector (note that
 * this inefficient due to the copying overhead of inserting into a
 * vector anywhere but at the end).
 */
int main() {
  vector<int> aVect;
  vector<int>::iterator itr;
  int i;

  for (i = 0; i <5; i++)
    aVect.push_back( i );

  cout << "Original contents of aVect:\n";
  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<int> (cout, "\n"));  

  itr = aVect.begin();
  itr += 2; // point to element 2

  insert_iterator<vector<int>> i_itr(aVect, itr);   
  *i_itr = 100;    // insert rather than overwrite
  *i_itr = 200;

  cout << "aVect after insertion:\n";
  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<int> (cout, "\n"));  
  return 0;
}
