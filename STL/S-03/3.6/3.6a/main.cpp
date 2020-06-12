#include <iostream>
#include <string>
using namespace std;

/**
 * The STL string class is not part of the STL.  However, it often
 * acts much like a form of a container of char data and can use the
 * STL iterators, algorithms, and functors.
 */
int main() {
  string my_letters = "abcdefghijklmnopqrstuvwxyz";

  auto i = 0;

  for(auto my_letter : my_letters)
    cout << ++i << " " << my_letter << endl;

  for (auto i = my_letters.cbegin();
       i != my_letters.cend();
       ++i)
    cout << *i << " " << endl;

  return 0;
}



