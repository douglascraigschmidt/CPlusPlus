#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

/**
 * Some examples of non-mutating search algorithms:
 * 
 * . find() - looks for a value in a range. 
 * 
 * . find_if() - looks for items in a range that satisfy a predicate. 
 * 
 * . find_first_of() - looks for items in first range that is also in
 *   the second range or uses a binary_predicate to find first matchig
 *   item.
 * 
 * . find_end() - looks backward for items in first range that are not
 *   also in the second range or uses a binary_predicate to find first
 *   non-matching item.
 * 
 * . adjacent_find() - looks for first pair in range that are equal,
 *   or match under a binary_predicate.
 *
 * Some example implementations of STL search algorithms:
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
  int a_begin[] = {10, 20, -30, 40, -50, 60};
  auto a_end = a_begin + sizeof(a_begin)/sizeof(*a_begin);

  // Find the first negative number.
  auto itr = find_if (a_begin,
                      a_end,
                      // The binder object "lives" only thruout the
                      // execution of the loop inside find_if(). The
                      // expression predicate(*i) inside find_if()
                      // simply calls the member function operator(),
                      // passing an int as parameter, which is each
                      // element of the list since that's what we get
                      // when we dereference the iterator.
                      bind (less<int>(), placeholders::_1, 0));

  if (itr != a_end) 
    cout << *itr << " is negative" << endl;

  return 0;
} 
 

#pragma clang diagnostic pop
