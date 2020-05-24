#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/**
 * This example shows how easy it is to switch from a vector of ints
 * to a vector of doubles.
 */
int main() {
  // Create an empty vector.
  vector<double> aVector;

  // Add several elements.
  aVector.push_back(1.2);
  aVector.push_back(4.5);

  aVector[1] = aVector[0] + 5.0;
  aVector[0] = 2.7; 		// now it has two elements: 2.7, 6.2

  // Print elements separated by a space using range-based
  // for loop and the auto keyword.
  for (auto d : aVector)
    cout << d << ' ';

  cout << endl;

  return 0;
}

