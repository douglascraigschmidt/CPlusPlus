/**
 * An ordered associative container is a container that supports
 * efficient insertion, removal, and lookup of elements (values) based
 * on keys. It supports insertion and removal of elements, but differs
 * from a sequential container because it doesn¡¦t let one insert an
 * element at a specific position or remove an element from a given
 * position based on the position itself -- all access is done to the
 * value using a key.  And once one adds the elements to the
 * container, the key cannot change, although the element and its key
 * can be removed. The STL provides four ordered associative
 * containers.
 * 
 * For sets and multisets there are only a group of values stored, but
 * they are stored in some kind of order keyed by the values. So if
 * the values are numbers, the ordering is by numeric value. If they
 * are letters, the collection is ordered by alphabetical order, OR
 * the values can be classes and the programmer can define a function
 * to base the key order upon.
 * 
 * For maps and multimaps there are actually two series of data that
 * go together hand in hand. One is the values and the other is called
 * the key. These are called pair associative containers because each
 * value is paired with a key. The keys cannot be changed by iterators
 * once they are assigned (you can, of course, erase a key).
 * 
 * Associative containers are implemented as binary trees. This means
 * that each element has a parent element and can have up to two child
 * elements. In addition, all ancestors to the left of an element have
 * lesser values and all ancestors to the right of an element have
 * greater values.
 */
