#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-bind"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

/**
 * C++ STL defines a family of replace*() algorithms:
 * . replace() - scan a range and replace given old values by given
 *   new value. 
 * . replace_if() - scan a range and replace given old values by given
 *   new value IF a predicate is true. 
 * . replace_copy() - make a copy of a range but replace given old
 *   values by given new value. 
 * . replace_copy_if() - make a copy of a range but replace given old
 *   values by given new value IF a predicate is true. 
 */
int main() {
  vector<int> v{10, -20, 11, 20, 10, -30, -47, -50, 63, 70};

  // printing vector elements
  cout << "before replacing, v: ";
  for (auto i : v)
    cout << i << " ";
  cout << endl;

  auto value = 20;

  // Replace -20 or 20 with 42
  replace_if(v.begin(), v.end(),
             [value](auto i) { return abs(i) == value; },
             42);

  cout << "after replacing abs(20) with 42, v: ";

  for (auto i : v)
    cout << i << " ";
  cout << endl;

  vector<int> v2(v.size());

  // Replace odd numbers with 0.
  std::replace_copy_if (v.begin(), v.end(),
                        v2.begin(), 
                        [](auto i) {
                          return (i % 2) == 1;
                        }, 0);

  cout << "after replacing odd numbers with 0, v2: ";

  for (auto i : v2)
    cout << i << " ";
  cout << endl;
}
