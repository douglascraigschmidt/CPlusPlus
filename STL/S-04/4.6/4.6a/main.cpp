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
int main() {
  // Create a list with one element whose value is 1.
  list<int> aList (1, 1);

  // Add new elements at the beginning and end of the list.
  aList.push_back(2);
  aList.push_front(0);

  // Explicitly define an iterator to first item.
  list<int>::iterator first = aList.begin();

  // Use auto to implicitly define an iterator to last item.
  auto last = aList.end();

  // Print the list's contents out in reverse order.
  while (last-- != first) {
    cout << *last << ' ';
  }

  return 0;
}

