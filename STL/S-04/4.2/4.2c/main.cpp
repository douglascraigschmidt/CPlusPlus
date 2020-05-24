#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * STL Iterator Advantages
 *
 * . The STL provides predefined iterators as a convenient abstraction
 *   for accessing many different types of containers
 * 
 * . Iterators for templated classes are generated inside the class
 *   scope with the syntax class_name<parameters>::iterator, so they
 *   can be directly used with their container.
 *
 * . Iterators can be thought of as limited (possible stateful)
 *   pointers, and can be dereferenced to get the values of elements
 *   pointed to, passed to stand-alone functions and algorithms to
 *   operate indirectly on the container and more.
 *
 * . An iterator can be a pointer or a class, and it can be derived
 *   from the STL's iterator class template. Any pointer can be
 *   treated as an iterator.
 *
 * STL Iterator Disadvantages
 *
 * . Iterators do not provide bounds checking; it is possible to
 *   overstep the bounds of a container, resulting in segmentation
 *   faults.
 *
 * . Different containers support different types of iterators by
 *   default, so it's not always possible to change the underlying
 *   container type without making changes to the code.
 *
 * . Iterators can be invalidated if the underlying container (the
 *   container being iterated over) is changed significantly.
 *
 * . Iterators have the same advantages and power as pointers. But
 *   they also have the same risks and inconveniences. For example,
 *   using a pointer we can accidentally modify data that we are not
 *   supposed to.
 */

// Create a typedef for a container.
// typedef list<long> container;
typedef vector<long> container;

/**
 * This example shows some disadvantages with STL iterators outlined above.
 */
int main() {
    // Create an empty container.
    container c (0);

    // Get an iterator to the beginning of the container.
    container::const_iterator it = c.begin();

    // Exceed the bounds of the iterator!
    do {
        cout << "value = " << *it++ << endl;
    } while (it != c.end());

    // Try to sort the container.
    sort(c.begin(), c.end());

    return 0;
}

