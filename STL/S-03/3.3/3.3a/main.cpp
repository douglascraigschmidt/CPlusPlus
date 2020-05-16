#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/**
   A vector is a collection of elements of type T, where T can be
   integer, double, char, or any class. It's a dynamic array that
   grows and shrinks at the end. A vector is a sequential container,
   i.e., its elements are ordered following a strict linear sequence.

   Vector containers are implemented as dynamic arrays. Just as
   regular arrays, vector containers have their elements stored in
   contiguous storage locations, which means that their elements can
   be accessed not only using iterators but also using offsets on
   regular pointers to elements.

   Unlike builtin C/C++ arrays, however, storage in vectors is handled
   automatically, allowing it to be expanded and contracted as needed.

   Vectors are efficient for:

   . Accessing individual elements by their position index. 
   . Iterating over the elements in any order.  
   . Adding and removing elements from the end. 

   Compared to builtin C/C++ arrays, they provide almost the same
   performance for these tasks, plus they have the ability to be
   easily resized. They usually consume a bit more memory than arrays,
   however, because their capacity is handled automatically, to allow
   for extra storage space for future growth.
*/
int main() {
  // Built-in arrays.
  int array[3];
  array[0] = 7;
  array[1] = array[0] + 3;
  array[2] = array[0] + array[1];

  // Print elements separated by a space
  for (int i = 0; i < (sizeof(array) / sizeof(array[0])); ++i)
    cout << array[i] << ' ';
  cout << endl;

  vector<int> v(3);
  v[0] = 7;
  v[1] = v[0] + 3;
  v[2] = v[0] + v[1]; // v[0] == 7, v[1] == 10, v[2] == 17

  // Print elements separated by a space
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << ' ';

  cout << endl;

  v.resize(0);

  // append elements with values 0-6
  for (int i=0; i < 7; ++i)
    v.push_back(i);

  // Another way to print elements separated by a space
  for (int i : v)
    cout << i << ' ';

  cout << endl;
  return 0;
}

