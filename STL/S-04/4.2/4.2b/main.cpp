#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

/**
 * We can use the iterator traits template to know what we need to
 * define when defining our own iterators or what we can check for
 * when using the STL predefined iterators.
 *
 * Here are the traits.
 *
 * . iterator_category must be one of these 5 values:
 *   input_iterator_tag, output_iterator_tag, forward_iterator_tag,
 *   bidirectional_iterator_tag, or random_access_iterator_tag. 
 *
 * . value_type is the base datatype of the iterator, and it can be
 *   void for output iterators since one cannot dereference them.
 *
 * . difference_type  is the difference between two iterators.
 *
 * . pointer is a pointer to the same datatype as the value_type is
 * 
 * . reference is a reference to the same datatype as the value_type
 *
 * Generic algorithms often need to have access to these traits
 * described on the previous page. Many STL algorithms take a range of
 * iterators, and they might need to declare a temporary variable
 * whose type is the iterators' value_type. The class iterator_traits
 * is a mechanism that allows such declarations.
 *
 * Here is an example of using a vector and various traits.
 */
int main() {
    list<double> dList{10.1, 20.2, 30.3, 40.4, 50.5};

    for (auto d : dList)
        cout << d << ' ';
    cout << endl;

    list<double>::iterator dListIter = dList.begin();
    // could use
    // auto dListIter = dList.begin();
    *dListIter = 100.1;

    for (auto d : dList)
        cout << d << ' ';
    cout << endl;

    list<double>::const_iterator dListConstIter = dList.cbegin();
    // could use
    // auto dListConstIter = dList.cbegin();

    list<double>::value_type d = *dListConstIter;
    // could use
    // auto d = *dListConstIter;

    // Compile error!
    // *dListConstIter = d;

    return 0;
}

 

 
