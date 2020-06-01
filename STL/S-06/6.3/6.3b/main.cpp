#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Here are the inserter function templates:
 *
 * template <typename Container>
 * back_insert_iterator<Container> back_inserter(Container& x) {
 *   return back_insert_iterator<Container>(x);
 * }
 * 
 * template <typename Container>
 * front_insert_iterator<Container> front_inserter(Container& x) {
 *   return front_insert_iterator<Container>(x);
 * }
 *
 * template <typename Container, typename Iterator>
 * insert_iterator<Container> inserter(Container& x, Iterator i) {
 *   return insert_iterator<Container>(x, Container::iterator(i));
 * }
 * 
 * These functions adapters (e.g., back_inserter()) leverage C++’s
 * implicit type inference feature for functions.
 */
int main() {
  vector<int> aVect1, aVect2;
  
  for(int i = 0; i <5; i++)
    aVect1.push_back(i);

  cout << "Original contents of aVect1:\n";
  copy (aVect1.begin (),
        aVect1.end (),
        ostream_iterator<int> (cout, "\n"));

  back_insert_iterator<vector<int> > bck_i_itr(aVect1);    
  *bck_i_itr++ = 100;        // insert rather than overwrite at end
  *bck_i_itr++ = 200;

  cout << "aVect1 after insertion:\n";
  copy (aVect1.begin (),
        aVect1.end (),
        ostream_iterator<int> (cout, "\n"));

  cout << "Size of aVect2 before copy: " << aVect2.size() << endl;

  copy(aVect1.begin(),
       aVect1.end(),
       back_inserter(aVect2));    
  cout << "Size of aVect2 after copy: " << aVect2.size() << endl;

  cout << "Contents of aVect12 after insertion:\n";
  copy (aVect2.begin (),
        aVect2.end (),
        ostream_iterator<int> (cout, "\n"));  
  return 0;
}
