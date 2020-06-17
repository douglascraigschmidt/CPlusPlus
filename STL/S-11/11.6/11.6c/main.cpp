#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

/**
 * Here's an example of STL vector and sort(), as well as count_if()
 * and remove_if().
 */
int main() {
  vector<int> v{1, 4, 2, 8, 5, 7};

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));

  auto sum = count_if (v.begin(),
                       v.end(),
                       bind(greater<>(), placeholders::_1, 5));

  cout << endl << "There are " << sum << " number(s) greater than 5" << endl;

  // "remove" all the elements less than 4.
  auto nend = remove_if(v.begin(),
                        v.end(),
                        bind(less<>(), placeholders::_1, 4));

  // remove_if() doesn't actually remove elements, but simply moves
  // unwanted elements to the end and returns an iterator pointing to
  // the first of these unwanted elements. It works this way because
  // it's a generic routine and it doesn't "know" whether the size of
  // the underlying data structure can be changed. However, v.erase()
  // does know, so it can remove the items from the vector.
  v.erase(nend, v.end());

  cout << "Elements less than 4 removed:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  // Sort the final results.
  sort(v.begin(), v.end());
  cout << "Elements sorted:" << endl;
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
} 
