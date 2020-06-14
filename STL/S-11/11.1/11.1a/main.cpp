/**
 * The term "mutating algorithms" may give the impression that these
 * types of algorithms always modify the elements in a container.
 * Some mutating algorithms do this, of course, but others simply
 * reorganize the elements based on some rule.
 * 
 * For example, all STL algorithms work with iterators.  Since
 * iterators can be used with different types of containers (or even
 * no containers, such as a native C-style array), algorithms can't
 * remove the value of elements. In addition, since they only receive
 * iterators, algorithms can't even figure out what container the
 * elements are in!
 * 
 * In particular, remove() and remove_if() only reorganize the
 * pointers to the elements, moving the "removed" elements to the end
 * of the sequence and returning an iterator that indicates the first
 * element that was "removed" (i.e., the first element that is not
 * part of the resulting sequence).  Therefore, other code must remove
 * the elements if they are no longer wanted in the container.
 * 
 * Here's a list of mutating algorithms
 * copy              copy_n           copy_backward   iter_swap
 * fill              fill_n           generate        generate_n
 * partition         [random_]shuffle random_sample   random_sample_n
 * replace           replace_if       replace_copy    replace_copy_if
 * remove            remove_if        remove_copy     remove_copy_if
 * reverse           reverse_copy     rotate          rotate_copy
 * stable_partition  swap             swap_ranges     transform
 * unique            unique_copy 
 */
