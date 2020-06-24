#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
using namespace std;

/**
 * This example shows how to apply the STL reverse() and reverse_copy()
 * algorithms.
 */
int main () {
  array<int, 10> my_array{1, 2, 3,
                          4, 5, 6,
                          7, 8, 9,
                          10};

  reverse(my_array.begin(),
          my_array.end());
  cout << "my_array contains: ";

  copy (my_array.begin (),
        my_array.end (),
        ostream_iterator<int> (cout, " "));
  cout << endl;

  string my_palindrome ("amanaplanacanalpanama");

  reverse_copy(my_palindrome.begin(),
               my_palindrome.end(),
               ostream_iterator<char>(cout));

  cout << endl;

  return 0;
}
