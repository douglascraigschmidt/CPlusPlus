#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Forward declarations.
 */
static void replace_builtin_array();
static void replace_vector();

/**
 * A forward iterator combines the features of an input iterator and
 * an output iterator. It permits values to be both accessed and
 * modified. Forward iterators support the following operations:
 * 
 * . constructor                   i(j);
 * . assignment operator           i=j;
 * . equality/inequality operator  i==j; i!=j;
 * . dereference operator          t = *j; *j=t; // Can assign & read
 * . pre/post increment operator   ++j; j++; 
 *
 * Ordinary pointers, like all iterators produced by containers in the
 * C++ Standard Library, can be used as forward iterators.
 * 
 * Forward Iterators can be either:
 * . constant, in which case one can access the object it points to,
 *   but one can't assign a new value to the element using this
 *   iterator
 *
 * . mutable, in which case one can both access the elements pointed
 *   to and also change them. 
 *
 * One STL function that uses forward iterators is the replace()
 * generic algorithm, which replaces occurrences of specific values
 * with other values, as shown in the example below.
 */
int main() {
  replace_builtin_array();
  replace_vector();

  return 0;
}

/**
 * Show how std::replace() can be used on a built-in array.
 */
static void replace_builtin_array() {
    // built-in array
    int a[] = {10, 20, 10, 20, 10, 30, 40, 50, 60, 70};

    // printing vector elements
    cout << "before replacing, a: ";
    for (auto i : a)
        cout << i << " ";
    cout << endl;

    // replacing 10 with 42
    replace(begin(a), end(a), 10, 42);

    // printing a elements
    cout << "after replacing, a: ";

    for (auto i : a)
        cout << i << " ";
    cout << endl;
}

/**
 * Show how std::replace() can be used on an STL vector.
 */
static void replace_vector() {
    // vector
    vector<int> v{10, 20, 10, 20, 10, 30, 40, 50, 60, 70};

    // printing vector elements
    cout << "before replacing, v: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // replacing 10 with 42
    replace(v.begin(), v.end(), 10, 42);

    // printing vector elements
    cout << "after replacing, v: ";

    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
