#include <iostream>
#include <iterator>
#include <set>
using namespace std;

/**
 * This example shows how set::insert() works.
 */
int main () {
  // Implicitly use less<int>.
  set<int> myset;

  for (int i = 1; i <= 5; i++)
    myset.insert(i * 10);    // set: 10 20 30 40 50

  // auto is pair<set<int>::iterator,bool>.
  auto ret = myset.insert(20);

  // No new element inserted.
  if (!ret.second) {
    // auto is set<int>::iterator
    auto it = ret.first;  // "it" now points to element 20

    myset.insert(it, 25); // max efficiency inserting
    myset.insert(it, 24); // max efficiency inserting
    myset.insert(it, 26); // no max efficiency inserting

    // 10 is already in set, not inserted.
    myset.insert({5, 10, 15});

    cout << "myset contains:" << endl;
    copy(myset.begin(),
         myset.end(),
         ostream_iterator<int>(cout, " "));

    cout << endl;
  }
  
  return 0;
}

