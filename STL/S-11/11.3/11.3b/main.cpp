#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

/**
 * This example shows how to apply the STL reverse() and reverse_copy()
 * algorithms.
 */
int main () {
  vector<int> myVect{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  reverse(myVect.begin(),
          myVect.end());       
  cout << "myVect contains:";

  copy (myVect.begin (),
        myVect.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  string my_palindrome ("amanaplanacanalpanama");

  reverse_copy(my_palindrome.begin(),
               my_palindrome.end(),
               ostream_iterator<char>(cout));

  cout << endl;

  return 0;
}
