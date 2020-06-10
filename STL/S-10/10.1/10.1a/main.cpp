/**
 * There are several header files containing the STL algorithms:
 *
 * #include <algorithm>
 * #include <numeric>   
 * #include <functional> - for the functors
 *
 * The Standard Template Library provides a number of simple, useful
 * and general algorithms to perform the most common operations on
 * groups and sequences of elements. These include traversals,
 * searching, sorting, as well as the insertion and removal of elements
 * in containers.
 *
 * These algorithms are implemented in a way that works well with the
 * containers and iterators, but they can also be used stand-alone with
 * custom code, as well as with standard C-style arrays and pointers.
 * 
 * No containers are passed to the algorithms, so programmers don't
 * even need a container.  Arguments to the algorithms are only data
 * ranges, i.e., iterator values, plus functors (if needed for "if"
 * predicates).  Algorithms can work with any type of calling function
 * that can pass the correct data to them.
 * 
 * There are various ways to categorize the STL algorithms. One way is
 * to use four categories:
 *  
 * . Non-mutating - Operate using a range of iterators, but don't
 *   change the data elements found, e.g., find(), equal(), and
 *   count().
 * 
 * . Mutating - Operate using a range of iterators, but can change the
 *   order of the data elements, e.g., copy(), remove(), swap(),
 *   generate(), and fill().
 * 
 * . Sorting and sets - Sort or searches ranges of elements and act on
 *   sorted ranges by testing values, e.g., sort(), set_union(), and
 *   set_intersection().
 * 
 * . Numeric - Type of algorithms that produce numeric results, e.g.,
 *   accumlate().
 * 
 * In addition to these main types, there are specific algorithms
 * within each type that accept a test condition, known as a
 * predicate. These are named ending with the _if() suffix to remind us
 * that they require an "if" predicate's result (true or false), as an
 * argument; these can be the result of functor calls.
 *  
 * There are several advantages of STL algorithms:
 * 
 * . STL algorithms are decoupled from the particular containers they
 *   operate on and are instead parameterized by iterators.
 * 
 * . All containers with the same iterator type can use the same
 *   algorithms.
 * 
 * . Algorithms are written to work on iterators rather than
 *   containers, so application programming is drastically
 *   reduced. For example, instead of writing a search routine for
 *   each kind of container, one only need write one for each iterator
 *   type and apply it any container. Since different containers can
 *   be accessed by the same iterators, just a few versions of the
 *   search routine must be implemented.
 */
