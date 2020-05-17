#include <list>
#include <iostream>
using namespace std;

/**
 * Bidirectional Iterators work with forward and multi-pass
 * algorithms. They allow traversing collections backward and forward.
 * A bidirectional Iterator can be incremented to obtain the next
 * element in a container, or decremented to obtain the previous
 * element.  Bidirectional iterators support the following operations: 
 *
 * . constructor                   i(j);
 * . assignment operator           i=j;
 * . equality/inequality operator  i==j; i!=j;
 * . dereference operator          t=*j; *j=t; // Can assign & read
 * . pre/post increment/decrement  ++j; j++; --i; i--;
 *   operators                     
 *
 * All standard STL containers (with the exception of forward_list)
 * provide bidirectional iterators or better.
 * 
 * Input, output and forward Iterators only support forward motion. An
 * iterator used to traverse a singly linked list, for example, need
 * only be a forward iterator, but an iterator used to traverse a
 * doubly linked list has to be a bidirectional iterator.
 *
 * A list’s default iterator is bidirectional, which we use in the
 * example below to print the list’s elements backwards.
 */
int main()   {
    list<int> aList (1, 1);
    aList.push_back (2);

    list<int>::iterator first = aList.begin();
    auto last = aList.end();

    while (last != first) {
        --last;
        cout << *last << ' '; // Could also be: cout << *--last << ' '
    }

    return 0;
}

