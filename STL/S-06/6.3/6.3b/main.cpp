#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Here's another example showing how to use a back_insert_iterator to
 * add elements to a container rather than overwrite them.
 */
int main() {
  vector<int> aVect1, aVect2;
  
  for(int i = 0; i <5; i++)
    aVect1.push_back(i);

  cout << "Original contents of aVect1:\n";
  copy (aVect1.begin (),
        aVect1.end (),
        ostream_iterator<int> (cout, "\n"));

  back_insert_iterator<vector<int>> bck_i_itr(aVect1);
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
