#include <iostream>
#include <list>
#include <iterator>
using namespace std;

/**
 * Characteristics of STL lists include the following:
 * 
 * . Has all the functions that vectors have except capacity(),
 *   reserve(), at(), and the [] operator.
 *
 * . Does not support random access iterators but does support
 *   bidirectional iterators, which allows both forward and backward
 *   transversal.
 * 
 * . Constant time insertion and removal of list elements anywhere
 *   (assuming an iterator points to the desired location).
 * 
 * . Iterators to deleted elements are invalid but inserting elements
 *   does not invalidate iterators (unless you remove the element that
 *   your iterator is pointing to!)
 *
 * Here's another example using a list along with its bi-directional
 * iterator.
 */
int main() {
  // Create an empty list.
  list<int> my_list;

  // Insert a new element at the end
  my_list.push_back(0);               

  // Insert a new element at the front.
  my_list.push_front(0);              

  // Insert "2" before 2nd element by incrementing the begin iterator.
  my_list.insert(++my_list.begin(), 2);
  // Insert "42" before final element by decrement the end iterator.
  my_list.insert(--my_list.end(), 42);

    // Insert two more elements at the end.
  my_list.push_back(5);
  my_list.push_back(6);

  // Print the contents of the list.
  for (auto i : my_list)
    cout << i << ' ';

  cout << endl;   
  return 0;
}


