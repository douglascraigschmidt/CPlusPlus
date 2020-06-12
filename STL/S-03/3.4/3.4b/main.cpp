#include <iostream>
#include <deque>
using namespace std;

/**
 * Efficiency of deque vs. vector:
 *
 * . When performing a large number of push_back() calls, use
 *   vector::reserve().
 * 
 * . When performing many de-allocations, deque takes longer to
 *   reclaim memory than vector since it is allocated using multiple
 *   "chunks."
 * 
 * . When using insert() or pop_front() with a deque is more efficient
 *   than vector.
 * 
 * . For element access, vector::at() or vector[] is better than
 *   deque's at() or deque[] methods.
 *
 * Here is another deque example that uses deque’s random access
 * iterators.
 */
int main() {
  deque<char> aDeck;

  for(size_t i = 0; i < 5; i++)
    aDeck.push_back(i + 'A');

  cout << "Original sequence: ";
  for(auto c : aDeck)
    cout << c << " ";
  cout << endl;

  // Here are two different ways to define an iterator!
  deque<char>::iterator it1 = aDeck.begin() + 2; // random access
  auto it2 = aDeck.begin() + 3;                  // iterators here!

  cout << "*it1: " << *it1 << ", ";
  cout << "*it2: " << *it2 << endl;
  cout << endl;

  // Modifies the deque by putting 'X' before the iterator.
  aDeck.insert(it1, 'X');

  cout << "Sequence after insert: ";
  for(auto c : aDeck)
    cout << c << " ";

  cout << endl;

  // These iterator dereferences may cause the program to crash since
  // STL does not implement "robust iterators" for deques.
  cout << "*it1: " << *it1 << ", ";
  cout << "*it2: " << *it2 << endl;

  return 0;
}

