#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The C++ standard library provides iterators for the standard
 * containers in STL (e.g., list, vector, and deque), and a few other
 * non-container classes, such as string.
 * 
 * The definition of iterators makes them much more than simple C/C++
 * pointers although they perform that type of behavior. They also
 * have a ‘state’, in other words they can hold data about
 * themselves. Their base classes are found in the header <iterator>.
 * 
 * An iterator gives a program access to the contents of a container
 * or other sequence of data, such as an I/O stream. One can think of
 * an iterator as an abstraction of a pointer; the syntax for using
 * iterators resembles that of pointers. 
 * 
 * An iterator points to a single element in a container or sequence
 * and can be advanced to the next element with the ++ (increment)
 * operator. The unary * (dereference) operator returns the element
 * that the iterator points to. Iterators, except for output
 * iterators, can be compared, and two iterators are equal if they
 * point to the same position in the same sequence, or if they both
 * point to one position past the end of the same sequence. 
 * 
 * There are also constant iterators defined for each container so
 * that a program can safely traverse a container without modifying
 * its elements. The STL algorithms that don’t modify container
 * elements (search, find etc) require const iterators as arguments. 
 *
 * Here's an example that shows how various types of vectors work with
 * their iterators:
 *
 * . Obtain an iterator to the first element in a container by calling
 *   that container's begin() member function.
 *
 * . Advance an iterator to the next element with the pre- or post-
 *   increment operator, as in ++it or it++ (it’s good practice to use
 *   ++it since this is more efficient).
 *
 * . Get the value the iterator refers to via the pointer dereference
 *   operator *, as in *it.
 */

/**
 * Forward declare print_const():
 */
static void print_const(const vector<int> &v);

/** 
 * . Determine if an iterator is at the end of a range by comparing it
 *   to the iterator returned by the container's end member function,
 *   which returns an iterator that refers to one past the end of the
 *   elements. This is why the continuation test for the for loop in
 *   the example above is it != v.end().
 */
int main () {
  // Create a vector initialized to a set of values.
  vector<int> v{1, 2, 3, 4, 5, 4, 3, 2, 1};

  // This example shows a vector with its iterator.  The double colon
  // :: indicates that the iterator is a "trait" of the vector.
  for (vector<int>::iterator it = v.begin();
       // The iterator returned by a container's end() member function
       // represents a logical element that's one *past* the last
       // element in a container, not the physical memory location
       // that's just beyond the last element.
       it != v.end();
       ++it) {
      cout << *it << ' ';
      // you can change the element(s) you're iterating over
      *it -= 1;
  }

  cout << endl;

  // Never dereference the value returned by v.end(), because it is
  // just a marker and holds nothing of value. The point of such a
  // construct is to provide a logical end marker for a range,
  // regardless of the context in which that range is used. 
  //
  // Standard algorithms and all member functions that work with a
  // range of iterators use this convention, which is why standard
  // algorithms like sort in <algorithm> work this way to sort every
  // element within the given range, but not including the iterator
  // used as the second argument to sort().
  sort(v.begin(), v.end());

  // Print the sorted results.
  print_const(v);

  // Create a vector of string.
  std::vector<std::string> sv{"hello", "world"};

  // Print the contents of the vector using an iterator.
  for (std::vector<std::string>::const_iterator itr = sv.cbegin();
       itr != sv.cend();
       ++itr)
    std::cout << "(" << itr->size() << ") " << *itr << ' ';

  std::cout << endl;

  // Print the contents of the vector using a range-based for loop.
  for (auto &str : sv)
    std::cout << "(" << str.size() << ") " << str << ' ';
}  

/**
 * It is always best to use a const object if the program doesn’t need
 * to modify its elements. Thus, if a program is using a const
 * container, the above code won't even compile. In that case, use a
 * const_iterator, which works just like the iterator type in the
 * example above, except that when it is dereferenced, it returns a
 * const object. Here is an example that works with const objects:
 */
static void print_const(const vector<int> &v) {
  for (vector<int>::const_iterator it = v.cbegin();
       it != v.cend();
       ++it) {
    cout << *it << ' ';
    // this is illegal with a const iterator:
    // *it = 100;
  }

  cout << endl;
}




