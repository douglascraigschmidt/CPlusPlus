/*
 * Iterator adaptors are types of iterators that operate on more than
 * just STL containers; they can also ‘adapt’ the standard containers’
 * iterators to work differently if that is desired.
 * 
 * Iterator adaptors turn the standard iterators into objects that can
 * operate in reverse, in insertion mode, and with streams.  In
 * particular, input, output, forward, bidirectional iterators can be
 * converted via the following adapted iterators:
 *
 * . Insert iterators 
 * . Reverse iterators 
 * . Stream iterators
 *
 * Insert iterators, also called inserters, change the assignment of a
 * new value into an insertion of that value into a sequence of
 * values, thus not overwriting other values. Note that these are
 * output iterators since they write values, and they override the
 * container’s assignment operator.
 *
 * The insert iterators allow insertion at the front, back or middle
 * of the elements depending upon the container type.
 *
 * There are several types of inserters and they also can change how
 * algorithms work:
 * 
 * Type	                  Function used	           Container
 * front_insert_iterator  push_front(value)        deque, list
 * 
 * back_insert_iterator   push_back(value)         vector, deque, list, string
 * 
 * insert_iterator   	  insert(value, position)  vector, deque, list,
 *                                                 map, and set
 * 
 * STL algorithms that copy elements, such as copy(), unique_copy(),
 * copy_backwards(), remove_copy(), & replace_copy(), are passed an
 * iterator that marks the position within a container to begin
 * copying.
 * 
 * With each element copied, the value is assigned and the iterator is
 * incremented. Each copy requires that we guarantee that the target
 * container is of a sufficient size to hold the set of assigned
 * elements. So we may need to expand the containers as we perform the
 * algorithm unless we want to make the containers huge from the
 * start…thus the inserters are useful. Start with an empty container,
 * and use the inserter along with the algorithms to make the
 * container grow only as needed.
 */
