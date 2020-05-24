#include <iostream>
#include <deque>
using namespace std;

/**
 * This example uses two deques of characters. In this example, after
 * elements are added to both deques, their sizes are printed out.
 * Then they are swapped using a deque member function and their sizes
 * now printed out. Finally the swap STL algorithm is used to swap
 * their elements.
 */
int main() {
  deque<char> myFirstDeck, myNextDeck;

  for(size_t i = 0; i <26; i++)
    myFirstDeck.push_back(i+'A');

  for(size_t i = 0; i <10; i++)
    myNextDeck.push_front(i+'0');

  cout << "Size of myFirstDeck and myNextDeck: ";
  cout << myFirstDeck.size() << " " << myNextDeck.size() << endl;
  cout << "myFirstDeck: ";

  for(auto i : myFirstDeck)
    cout << i;
  cout << endl << "myNextDeck: ";

  for(auto i : myNextDeck)
    cout << i;
  cout << "\n\n";

  // swap deque elements using member function.
  myFirstDeck.swap(myNextDeck);

  cout << "Size of myFirstDeck and myNextDeck after first swap: ";
  cout << myFirstDeck.size() << " " << myNextDeck.size() << endl;

  cout << "myFirstDeck after first swap: ";
  for(char i : myFirstDeck)
    cout << i;
  cout << endl;

  cout << "myNextDeck after first swap: ";

  for(char i : myNextDeck)
    cout << i;
  cout << "\n\n";

  swap(myFirstDeck, myNextDeck);

  return 0;
}



