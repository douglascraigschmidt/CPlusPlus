/* Sequential containers 

Sequential containers are collections of data elements placed in some
order, usually according to when the element was added to the
container. The order of the elements has nothing to do with their
value. The non-vector sequential containers are something like arrays,
but don't have to be physically contiguous in storage.

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






