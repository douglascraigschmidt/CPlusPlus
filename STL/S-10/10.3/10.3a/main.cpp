#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-avoid-bind"
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <algorithm>
#include <iostream>
#include <functional>
#include <list>
using namespace std;

/**
 * Some examples of non-mutating find*() family of algorithms:
 * 
 * . find() - looks for a value in a range. 
 * 
 * . find_if() - looks for items in a range that satisfy a predicate. 
 * 
 * . find_first_of() - looks for items in first range that is also in
 *   the second range or uses a binary_predicate to find first matching
 *   item.
 *
 * Some example implementations of STL find algorithms:
 *
 * template <typename InputIterator, typename T>
 * InputIterator find(InputIterator first, InputIterator last, 
 *                    const T& value) { 
 *     while (first != last && *first != value) ++first; 
 *     return first; 
 * }
 * 
 * template <typename InputIterator, typename Predicate> 
 * InputIterator find_if(InputIterator first, InputIterator last, 
 *                       Predicate pred) {
 *     while (first != last && !pred(*first)) ++first; 
 *     return first; 
 * } 
 *
 * These templates can be used with pointers, iterators or even with
 * const iterators as the first two arguments (or any datatype that
 * supports the unary * and ++ operators). The third parameter can be
 * any value that supports comparison with the type *i.
 */

/**
 * This example uses the find_if() algorithm on a built-in array and a
 * functor, rather than simply using a pointer or iterator.
 */
int main() {
  int a[] = {10, 20, -30, 40, -50, 60};

    // Find the first negative number.
  auto itr1 = find_if (begin(a),
                       end(a),
                       // The binder object "lives" only thruout the
                       // execution of the loop inside find_if(). The
                       // expression predicate(*i) inside find_if()
                       // simply calls the member function operator(),
                       // passing an int as parameter, which is each
                       // element of the list since that's what we get
                       // when we dereference the iterator.
                       bind (less<>(), placeholders::_1, 0));

  if (itr1 != end(a))
    cout << *itr1 << " is first negative" << endl;

  // Find the last negative number.
  auto itr2 = find_if (rbegin(a),
                       rend(a),
                       bind (less<>(), placeholders::_1, 0));

  if (itr2 != rend(a))
    cout << *itr2 << " is last negative" << endl;

  return 0;
} 

#pragma clang diagnostic pop
