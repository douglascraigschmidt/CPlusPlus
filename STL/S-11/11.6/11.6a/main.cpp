/*
 * Sorting algorithms are a special type of mutating algorithms which
 * change the positions of data elements in a collection. Searching *
 * and comparison algorithms are special types of non-mutating
 * algorithms that work best with sorted data.
 * 
 * In general, programming algorithms are often categorized by their
 * efficiency, which means how long they take to run and how much
 * storage or memory is used during their running. This is most
 * important for those that sort or search large collections of data.
 * 
 * Several algorithms that perform searching or comparison operations
 * require sorted input in order to work correctly: binary_search,
 * equal_range, inplace_merge, includes, lower_bound, merge,
 * set_difference, set_intersection, set_symmetric_difference,
 * set_union and upper_bound. The unique and unique_copy algorithms
 * work best with sorted input, but don’t require it.
 * 
 * Therefore, it is important to choose the most efficient sort
 * algorithm for the task on hand. We define efficient in terms of
 * time using the concept of complexity.
 * 
 * Algorithmic complexity is generally discussed in a form known as
 * Big-O notation, where the O represents the complexity of the
 * algorithm and a value n represents the size of the set the
 * algorithm is run against. For example, O(n) means that an algorithm
 * has a linear complexity.
 * 
 * For linear processes, it takes ten times longer to operate on a set
 * of 10 items than it does on 1 item and ten times longer again to
 * operate on 100 items than it does on a set of 10 items (10 * 10 =
 * 100). So if reading a file of 10 lines takes 1 CPU millisecond then
 * reading a file containing 100 lines would take 100 milliseconds for
 * a linear algorithm. This is the complexity of a one loop algorithm.
 * 
 * But if the complexity is O(n2) (quadratic complexity), then it
 * takes 100 times longer to operate on a set of 100 items than it
 * does on a set of 10 items. This type of algorithm has 2 nested
 * loops with one inside another. The sorting algorithms that are
 * O(n2) in efficiency include the bubble, insertion, selection and
 * shell sorts.
 * 
 * Finally, there are some sorting algorithms which have complexity of
 * O(n log n): the heap, merge, and quick sorts. These algorithms are
 * fast, but that speed comes at the cost of complexity; these
 * algorithms use recursion, advanced data structures and multiple
 * arrays.
 *       
 * The most important thing is to choose the sorting algorithm that is
 * most appropriate for a custom program. Here is a list of the STL
 * sorting, set, and heap algorithms:
 * 
 * adjacent_difference            binary_search
 * equal_range                    includes        
 * inplace_merge                  is_heap
 * is_sorted                      lexicographical_compare
 * lexicographical_compare_3way   lower_bound 
 * make_heap                      max
 * max_elementmerge               min
 * min_element                    nth_element
 * partial_sort partial_sort_copy pop_heap
 * power                          push_heap
 * set_difference                 set_intersection
 * set_union                      set_symmetric_difference
 * stable_sort                    sort
 * sort_heap                      upper_bound     
 */
