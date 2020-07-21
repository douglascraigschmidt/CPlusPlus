/**
 * STL containers are classes whose objects can be used to build
 * collections of data of same type, like built-in C++ arrays.
 * However, these collections also have data and functions because
 * they are objects.
 * 
 * Common characteristics of STL containers include the following:
 *
 * 1. They copy the values of their elements when inserted rather than
 *    maintaining references to these elements. This is called ‘value
 *    semantics’. Thus anything added to an STL container must be able
 *    to be copied; a user defined class must define a public copy
 *    constructor or to use the class objects with an STL container,
 *    pointers to the objects must be stored in the container.
 *
 * 2. All elements added to “classic” STL containers have an order; in
 *    sequential containers this is maintained by the order added to
 *    the container; in associative containers, a key value provides
 *    the ordering.
 *
 * 3. Operations on the elements of an STL container are not tested by
 *    the container for being correct or safe: a program using the STL
 *    must provide its own exception handling code for any errors that
 *    might occur. 
 *
 * Common operations of STL containers include the following:
 *
 * 1. Initialization constructors: Each container supports both
 *    default and copy constructors, plus a destructor. Containers can be
 *    initialized with a range of values as well. 
 * 
 * 2. Size functions: There are 3 functions related to a container’s
 *    size. They are: size(), which returns the actual number of
 *    elements in the container, empty(), checks whether there are any
 *    elements at all in the container, and max_size(), which returns
 *    the maximum number of elements the container can contain.
 *
 * 3. Comparison operators: The equality and relational operators, ==, 
 *    !=, <, <=, >, >= are defined for containers holding the same
 *    datatype as elements. Two containers are equal if all elements
 *    are equal and in the same order. The relational operators work
 *    by comparing the containers element-by-element. If one container
 *    has fewer elements it is ‘less than’ the other. If a container’s
 *    element value is less than the value of that element at the same
 *    index in the other container this contain is also ‘less than’
 *    the other one. If the comparison test runs thru both containers
 *    and they are of equal size with identical elements in the same
 *    order, they are equal and the < or > relational operator returns
 *    false for whatever it is testing for.
 *
 * 4. Assignments and swap() function: When one container is assigned
 *    to another one, all elements in the source container are copied
 *    by value into the destination container, and all old elements
 *    are removed. This takes time.  A faster way to get this done if
 *    the source container will not be needed afterward, is to use the
 *    swap() function instead. This will swap the internal pointers to
 *    the container’s elements, allocator and sorting criteria, and is
 *    very fast and exception-safe.
 */

/**
 * Sequential containers.
 */ 

// vector - Linear and contiguous storage like an array that allows
// fast insertions and removals at the end only.
#include <vector>

// list - Doubly linked list that allows fast insertions and removals
// anywhere.
#include <list>

// forward_list - Single linked list that allows fast insertions and
// removals anywhere.
#include <forward_list>

// deque - Linear but non-contiguous storage that allows fast
// insertions and removals at both ends.
#include <deque>

/**
 * Ordered associative containers 
 */

// set - Defines where the elements' values are the keys and
// duplicates are not allowed. It has fast lookup using the key.
#include <set>

// multiset - Defines where the elements' values are the keys and
// duplicates are allowed. It has fast lookup using the key.
#include <set>

// map - Key-to-value mapping where a single key can only be mapped to
// one value,
#include <map>

// multimap - Key-to-value mapping where a single key can be mapped to
// many values.
#include <map>

/**
 * Unordered associative containers 
 */

// unordered_set - Defines where the elements' values are the keys and
// duplicates are not allowed. It has fast lookup using the key.
#include <unordered_set>

// unordered_multiset - Defines where the elements' values are the keys and
// duplicates are allowed. It has fast lookup using the key.
#include <unordered_set>

// unordered_map - Key-to-value mapping where a single key can only be mapped to
// one value,
#include <unordered_map>

// unordered_multimap - Key-to-value mapping where a single key can be mapped to
// many values.
#include <unordered_map>

/**
 * Adapter containers 
 */

// stack - First in, last out data structure.
#include <stack>

// queue - First in, first out data structure.
#include <queue>

// priority_queue - A queue that maintains items in a sorted order based on a priority value.
#include <queue>





