#include <iostream>
#include <vector>
using namespace std;

/**
 * Forward declarations.
 */
static void demonstrate_pointer_arithmetic();
static void demonstrate_random_access_iterators();

/**
 * Random-access iterators allow the operations of pointer arithmetic:
 * addition of arbitrary offsets, subscripting, and subtraction of one
 * iterator from another to find a distance.  These are the most
 * powerful iterators and are like regular pointers but they are also
 * smart, e.g., they can hold state.
 *
 * In addition doing all that bidirectional iterators do, random
 * access iterators can do the following as well:
 * . operator+ (int) 
 * . operator+= (int) 
 * . operator- (int) 
 * . operator-= (int) 
 * . operator- (random access iterator) 
 * . operator[] (int) 
 * . operator < (random access iterator) 
 * . operator > (random access iterator) 
 * . operator >= (random access iterator) 
 * . operator <= (random access iterator) 
 *
 * This example demonstrates how the STL vector class provides a
 * random access iterator that can be used in a manner that's nearly
 * identical to pointer arithmetic on a C++ built-in array.
 */
int main() {
  demonstrate_pointer_arithmetic();
  demonstrate_random_access_iterators();

  return 0;
}

/**
 * Demonstrate pointer arithmetic with a C++ built-in array.
 */
static void demonstrate_pointer_arithmetic() {
  // Create a array of 10 numbers.
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Keep track of the total number of even values.
  auto total_even = 0;

  // Iterate through the vector summing the values of even numbers.
  for (auto ip = begin(a);
       ip != end(a);
       // Use pointer's += operator to skip over odd numbers.
       ip += 2)
    total_even += *ip;

  cout << "Sum of even numbers = " << total_even << endl;
}

/**
 * Demonstrate random access iterators with a vector.
 */
static void demonstrate_random_access_iterators() {
  // Create a vector of 10 numbers.
  vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // Keep track of the total number of even values.
  auto total_even = 0;

  // Iterate through the vector summing the values of even numbers.
  for (auto iter = begin(v);
       iter != end(v);
       // Use iter's += operator to skip over odd numbers.
       iter += 2) 
    total_even += *iter;

  cout << "Sum of even numbers = " << total_even << endl;
}
