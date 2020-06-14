#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

/**
 * The remove_copy() algorithm copies the values of the elements in
 * the range [first,last) to the range positions beginning at result,
 * except for the elements that compare equal to value, which are not
 * copied.  Here's an example of remove_copy().
 */
int main () {
  int a[] = {10, 20, 30, 30, 20, 10, 10, 20};          

  cout << "original array contains:";
  copy (begin(a),
        end(a),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  vector<int> myVect;

  remove_copy (begin(a), end(a), back_inserter (myVect), 20); 

  cout << "after removing all 20's myVect contains:";
  copy (myVect.begin(),
        myVect.end(),
        ostream_iterator<int> (cout, " "));
  cout << endl;
  return 0;
}
