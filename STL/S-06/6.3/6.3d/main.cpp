#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
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
 * insert_iterator<deque<int>> (aDeck, aDeck.end());
 *
 * One can also declare back and front inserters like this using a
 * deque:
 * 
 * deque<int> aDeck;
 * back_insert_iterator<deque<int>>	backItr (aDeck);
 * front_insert_iterator<deque<int>> forwardItr (aDeck);
 *
 * Here is the inserter() function template:
 *
 * template <typename Container, typename Iterator>
 * insert_iterator<Container> inserter(Container& x, Iterator i) {
 *   return insert_iterator<Container>(x, Container::iterator(i));
 * }
 * 
 * This function iterator adapter leverages C++'s implicit type
 * inference feature for functions.
 */

/**
 * Forward declaration.
 */
template <typename Container>
void insert_into_container (Container &c);

/**
 * Here is an example using an insert iterator for vector (note that
 * this inefficient due to the copying overhead of inserting into a
 * vector anywhere but at the end).
 */
int main() {
  list<int> aList {0, 1, 2, 3, 4};
  vector<int> aVect {0, 1, 2, 3, 4};
  set<int> aSet {0, 1, 2, 3, 4};

  insert_into_container(aVect);
  insert_into_container(aList);
  insert_into_container(aSet);

  return 0;
}

template <typename Container>
void insert_into_container (Container &c) {
  cout << "Original contents of container:\n";
  copy(c.cbegin(),
       c.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  auto itr = c.begin();
  itr++; // Advance iterator by two elements.
  itr++; 

  insert_iterator<Container> i_itr(c, itr);
  *i_itr++ = 100;    // insert rather than overwrite
  *i_itr++ = 200;

  cout << "Container after insertion:\n";
  copy(c.cbegin(),
       c.cend(),
       ostream_iterator<int>(cout, " "));
  cout << endl;
}
