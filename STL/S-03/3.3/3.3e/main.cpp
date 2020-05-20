#include <vector>
#include <iterator>
#include <iostream>
#include <numeric>
using namespace std;

/**
 * Tips for applying vectors efficiently:
 * 
 * . Provide rapid indexed access with the overloaded subscript
 *   operator[] since they are stored in contiguous memory like a C or
 *   C++ raw array.
 *
 * . Support random-access iterators. All STL algorithms can operate
 *   on a vector. The iterators for a vector are normally implemented
 *   as pointers to elements of the vector.
 *
 * . It is faster to insert many elements at once than one at a time.
 * 
 * . Vector is the type of sequenced template that should be used by
 *   default if you don't need to access both ends of the collection
 *   and you don't need to traverse it backwards.
 *
 * This example shows how to sum the contents in a vector by
 * deferencing an iterator.
 */
int main() {
  // Create a vector using an initializer list.
  vector<int> aVector {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Auto-deduce the type of total.
  auto total = 0;
  for (auto anIterator = aVector.begin(); // set iterator at start
       anIterator != aVector.end();
       ++anIterator)  	                  // process vector using iterator
    total += *anIterator;                 // add up values stored

  cout << "Total = " << total << endl;    // display the total of values

  total = 0;
  for (int anIterator : aVector)          // process vector using range-based loop
       total += anIterator;               // add up values stored

  cout << "Total = " << total << endl;    // display the total of values

  // Here are same results obtained via an STL algorithm.
  cout << "Total = "
       << std::accumulate(aVector.begin(), aVector.end(), 0)
       << endl;

  return 0;
}

