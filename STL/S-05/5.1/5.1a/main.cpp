#include <iostream>
#include <utility>
using namespace std;

/**
 * An ordered associative container is a container that supports
 * efficient insertion, removal, and lookup of elements (values) based
 * on keys. It supports insertion and removal of elements, but differs
 * from a sequential container because it doesn't allow the insertion
 * of an element at a specific position or remove an element from a
 * given position based on the position itself -- all access is done
 * to the value using a key.  After an element has been added to a
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
 * 
 * The following are STL predefined ordered associative containers:
 *
 * set<key>             Supports unique keys only and provides fast key retrieval
 * multiset<key>        Supports duplicate keys, also fast key retrieval
 * map<key, value>      Supports unique keys only, and fast retrieval
 *                      of type T data based on the key  
 * multimap<key, value> Supports duplicate keys, otherwise performs like map.
 * 
 * You can also create a custom associative container and use it with
 * the STL iterators, algorithms, and functions.
 *
 * What are the applications of such containers? Think of a symbolic
 * debugger. It can use an associative container that maps strings
 * (variable names) to memory addresses (the variables'
 * addresses). This way, when one evaluate or modify a variable by its
 * name, the debugger knows where that variable is stored in memory.
 * 
 * Another example is a phone book, in which names serve as keys, and
 * telephone numbers are their associated values.
 */

