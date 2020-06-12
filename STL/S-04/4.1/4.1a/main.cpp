#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

/**
 * An iterator in C++ is a concept that implements the iterator design
 * pattern into a specific set of behaviors that work well with the
 * C++ standard library. The standard library uses iterators to work
 * with elements in a range in a consistent manner. Anything that
 * implements this set of behaviors is called an iterator.
 *
 * The iterator pattern defines a handful of simple requirements. An
 * iterator should allow its consumers to:
 *
 * . Move to the beginning of the range of elements.
 * . Advance to the next element.
 * . Return the value referred to.
 * . Query it to see if it is at the end of the range.
 *
 * Iterators are defined by the operations that they must support. And
 * because the underlying representation of an iterator is usually
 * implementation independent, one can use a regular pointer, an
 * integer, or a class object so long as it supports the operations *,
 * ++, = and ==.
 * 
 * Their capabilities range from the random access iterator that has
 * all of the power of a regular C++ pointer, to the input and output
 * iterators that can only go forward in a collection either reading
 * or writing. In between are the bi-directional, reverse, insertion,
 * stream and forward iterators. Each is a class with its own member
 * functions, overloaded operators and data.
 *
 * The following overloaded operators are defined for more iterators:
 *
 * *it;	Use dereference (*) op to get/set value
 * ++it;	Points to next element. Value after update
 * it++;	Points to next element. Value before update
 * it2 = it2;	Assignment
 * it1 == it2;	Equality comparison
 * it1 != it2;	Inequality
 * 
 * Additional operators for bidirectional iterators include:
 * 
 * --it;	Pre-decrement
 * it--;	Post-decrement. May be less efficient
 * 
 * Additional operators for random-access iterators include:
 * 
 * it += i;	Increments it by i positions
 * it -= i;	Decrements it by i positions
 * it2 + I;	Increments it by i positions
 * it2 – I;	Decrements it by i positions
 * it[i];	Returns reference to ith element after it
 * it1 < it2;	Comparison
 * it1 <= it2;	Comparison
 * it1 > it2;	Comparison
 * it1 <= it2;	Comparison
 * 
 * Each predefined standard STL container comes with its own iterator
 * accessible via its *begin() and *end() factory methods.  STL
 * container iterators can a random access iterator, a bidirectional
 * iterator, or some another type.  However, you can always use an
 * additional type of iterator if the predefined one doesn't work as
 * needed.  Likewise, you can define a custom iterator based on the
 * STL predefined classes.
 * 
 * Iterators are central to generic programming because they are an
 * interface between containers and algorithms. Algorithms usually
 * take iterators as arguments, so for an algorithm to work with a
 * container, a container must provide a way to access its elements
 * using iterators.
 */

namespace my_copy {
  /**
   * This function shows a typical implementation of the copy()
   * template function, which is a common STL algorithm that uses
   * iterators.
   */
  template<typename InputIterator, typename OutputIterator>
  OutputIterator copy(InputIterator first,
                      InputIterator last,
                      OutputIterator result) {
    // Iterate from first to last, incrementing as we go!
    for (; first != last; ++first, ++result)

      // *result is “written to”, whereas *first is “read from”
      *result = *first;
    return result;
  }
}

/**
 * This example shows how to use the copy() algorithm to copy the
 * contents of one built-in array to another.
 */
int main () {
  // Create built-in arrays.
  int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int a1_size = sizeof(a1) / sizeof(a1[0]);
  int a2[a1_size];

  // Perform the copy.
  my_copy::copy(begin(a1), end(a1), a2);

  // Print the results.
  for (auto i : a2)
    cout << i << ' ';
  cout << endl;

  // Create STL vectors.
  vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> v2(v1.size());

  // Perform the copy.
  my_copy::copy(v1.begin(), v1.end(), v2.begin());

  // Print the results.
  for (auto i : v2)
    cout << i << ' ';

  cout << endl;
}





