/* Sequential containers 

Sequential containers are collections of data elements placed in some
order, usually according to when the element was added to the
container. The order of the elements has nothing to do with their
value. The non-vector sequential containers are something like arrays,
but don¡¦t have to be physically contiguous in storage.

Sequential containers are better than simple C/C++ arrays because:

. They have a size() member function
. They provide a past end entry iterator
. They provide copy constructors
. They allow assignment
. Can be passed by value
. They grow and shrink dynamically, i.e., they know how to cleanup
  after themselves because they have destructors
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

/* Ordered associative containers 

An ordered associative container is a container that supports
efficient insertion, removal, and lookup of elements (values) based on
keys. It supports insertion and removal of elements, but differs from
a sequential container because it doesn¡¦t let one insert an element at
a specific position or remove an element from a given position based
on the position itself ¡V all access is done to the ¡¥value¡¦ using a
key.  And once one adds the elements to the container, the key cannot
change, although the element and its key can be removed. The STL
provides four ordered associative containers.

For sets and multisets there are only a group of values stored, but
they are stored in some kind of order keyed by the values. So if the
values are numbers, the ordering is by numeric value. If they are
letters, the collection is ordered by alphabetical order, OR the
values can be classes and the programmer can define a function to base
the key order upon.

For maps and multimaps there are actually two series of data that go
together hand in hand. One is the values and the other is called the
key. These are called pair associative containers because each value
is paired with a key. The keys cannot be changed by iterators once
they are assigned (you can, of course, erase a key).

Associative containers are implemented as binary trees. This means
that each element has a parent element and can have up to two child
elements. In addition, all ancestors to the left of an element have
lesser values and all ancestors to the right of an element have
greater values. */

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

/* Unordered associative containers */

// set - Defines where the elements' values are the keys and
// duplicates are not allowed. It has fast lookup using the key.
#include <unordered_set>

// multiset - Defines where the elements' values are the keys and
// duplicates are allowed. It has fast lookup using the key.
#include <unordered_set>

// map - Key-to-value mapping where a single key can only be mapped to
// one value,
#include <unordered_map>

// multimap - Key-to-value mapping where a single key can be mapped to
// many values.
#include <unordered_map>

/* Adapter containers */

// stack - First in, last out data structure.
#include <stack>

// queue - First in, first out data structure.
#include <queue>

// Queue that maintains items in a sorted order based on a priority value.
#include <priority_queue>





