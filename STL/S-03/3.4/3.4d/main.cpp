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
  deque<char> myFirstDeck, mySecondDeck;

  for(size_t i = 0; i < 26; i++)
    myFirstDeck.push_back(i +'A');

  for(size_t i = 0; i < 10; i++)
    mySecondDeck.push_front(i + '0');

  cout << "Size of myFirstDeck and mySecondDeck: ";
  cout << myFirstDeck.size() << " " << mySecondDeck.size() << endl;
  cout << "myFirstDeck: ";

  for(auto i : myFirstDeck)
    cout << i;
  cout << endl << "mySecondDeck: ";

  for(auto i : mySecondDeck)
    cout << i;
  cout << "\n\n";

  // swap deque elements using member function.
  myFirstDeck.swap(mySecondDeck);

  cout << "Size of myFirstDeck and mySecondDeck after first swap: ";
  cout << myFirstDeck.size() << " " << mySecondDeck.size() << endl;

  cout << "myFirstDeck after first swap: ";
  for(auto c : myFirstDeck)
    cout << c;
  cout << endl;

  cout << "mySecondDeck after first swap: ";

  for(char i : mySecondDeck)
    cout << i;
  cout << "\n\n";

  swap(myFirstDeck, mySecondDeck);

  return 0;
}



