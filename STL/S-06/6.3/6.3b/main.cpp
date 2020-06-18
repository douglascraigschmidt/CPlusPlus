#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Here's another example showing how to use a back_insert_iterator to
 * add elements to a container rather than overwrite them.
 */
int main() {
  vector<int> aVect1 {0, 1, 2, 3, 4}, aVect2;

  cout << "Original contents of aVect1:\n";
  copy (aVect1.begin (),
        aVect1.end (),
        ostream_iterator<int> (cout, "\n"));

  back_insert_iterator<vector<int>> itr(aVect1);
  // auto itr = aVect1.begin();
  *itr++ = 100;        // insert rather than overwrite at end
  *itr++ = 200;

  cout << "aVect1 after insertion:\n";
  copy (aVect1.begin (),
        aVect1.end (),
        ostream_iterator<int> (cout, "\n"));

  cout << "Size of aVect2 before copy: " << aVect2.size() << endl;

  copy(aVect1.begin(),
       aVect1.end(),
       back_inserter(aVect2));    
  cout << "Size of aVect2 after copy: " << aVect2.size() << endl;

  cout << "Contents of aVect2 after insertion:\n";
  copy (aVect2.begin (),
        aVect2.end (),
        ostream_iterator<int> (cout, "\n"));

  if (equal(aVect1.begin(), aVect1.end(), aVect2.begin()))
      cout << "vectors are equal" << endl;
  else
      cout << "end of the world" << endl;
  return 0;
}
