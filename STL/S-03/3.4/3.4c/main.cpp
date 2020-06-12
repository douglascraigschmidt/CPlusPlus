#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

/**
 * An example of printing the contents of a deque via its const
 * iterator.
 */
template <typename T>
void print(const deque<T> &d) {
  cout << "The number of items in the deque:" 
       << d.size() << endl;

  for (typename deque<T>::const_iterator iter = d.cbegin();
       iter != d.cend();
       ++iter) {
    // *iter = T(); illegal!
    cout << *iter << " ";
  }

  cout << endl << endl;
}

/**
 * This example uses the deque functions push_back(), insert(), and
 * begin(), as well as an example of a function with a deque that uses
 * const iterator to copy the members to the output stream.
 */
int main() {
    deque<int> aDeck;

    aDeck.push_back(3);
    aDeck.push_front(1);

    // Insert before aDeck[1].
    aDeck.insert(aDeck.begin() + 1, 2);
    aDeck[2] = 0;

    print(aDeck);
    return 0;
}


