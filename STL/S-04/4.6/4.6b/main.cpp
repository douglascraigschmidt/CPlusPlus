#include <list>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>

#include"simple_string.h"
#include <algorithm>

using namespace std;

/**
 * This example uses a list's bidirectional iterator with the
 * algorithms copy() and reverse_copy().  It also demonstrates
 * the difference between emplace_back() and push_back().
 */
int main() {
  // Create an empty list.
  list<simple_string> aList;

  cout << "starting emplace_back() calls" << endl;

  // Use emplace_back() to add items to the list, which
  // is more efficient than push_back().
  aList.emplace_back("peach");
  aList.emplace_back("apple");
  aList.emplace_back("bananas");
  cout << "ending emplace_back() calls" << endl;

  cout << "starting push_back() calls" << endl;
  // Use push_back() to add items to the list.
  aList.push_back("peach");
  aList.push_back("apple");
  aList.push_back("bananas");
  cout << "ending push_back() calls" << endl;

  // Make y the same size - creates empty strings for y's elements.
  list<simple_string> y(aList.size());

  // This is the STL algorithm reverse_copy(), where the source is
  // aList and the target is y.
  reverse_copy(aList.begin(),
               aList.end(),
               y.begin());  

  // Print result forwards.
  copy (y.begin(),
        y.end(),
        ostream_iterator<simple_string>(cout, " "));
  cout << endl;

  // Print result backwards.
  copy (y.rbegin(),
        y.rend(),
        ostream_iterator<simple_string>(cout, " "));
  cout << endl;
  return 0;
}
