/**
 * Non-mutating algorithms don't change the contents of what is found.
 * These algorithms typically do lookup and counting operations, such as
 * 
 * . adjacent_find() - Finds two items adjacent to each other 
 * . count() - Returns a count of elements matching a given value
 * . count_if() - Returns a count of elements for which a predicate is true 
 * . equal() - Determines if two sets of elements are the same
 * . find() - Finds a specified value in a given range 
 * . find_if() - Finds the first element for which a predicate is true
 * . find_if_not() - Finds the first element for which a predicate is false
 * . find_end() - Finds last sequence of elements in a range
 * . find_first_of() - Finds first sequence of elements in a range
 * . for_each() - Applies a function to a range of elements
 * . mismatch() - Finds the first position where two ranges differ
 * . search() - Searches for a range of elements
 * . search_n() - Searches for n consecutive copies of an element within a
 *   range
 * 
 * Note that unexpected behavior can result if two sequences or
 * strings of unequal size are compared. STL will not warn one or
 * prevent this, so you need to have error checking in custom code.
 */
