#include <iostream>
#include <list>
using namespace std;

/**
 * This example uses two deques of characters. In this example, after
 * elements are added to both deques, their sizes are printed out.
 * Then they are swapped using a deque member function and their sizes
 * now printed out. Finally the swap STL algorithm is used to swap
 * their elements.
 */
int main() {
  list<char> aList;

  for(int i = 0; i < 10; i++)
    aList.push_back('A' + i);

  cout << "Size = " << aList.size() << endl;
  cout << "Contents: ";

  while (!aList.empty ()) {
    auto p = aList.begin();

    cout << *p;

    aList.pop_front();
  }

  return 0;
}



