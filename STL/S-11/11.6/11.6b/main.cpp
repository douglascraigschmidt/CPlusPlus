#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/**
 * merge() uses the merge sort algorithm and combines two sorted ranges
 * into a single sorted range of data. There are two versions: one
 * uses the < operator for comparisons and the other requires a
 * functor comparator. inplace_merge is another STL merge sort
 * algorithm.
 * 
 * partial_sort() and partial_sort_copy() use the heap sort algorithm and
 * sort the entire range of data.  Both heap sort and introsort have
 * the same complexity, but introsort is usually faster.
 * 
 * stable_sort() uses the merge sort algorithm. If one are sorting a
 * sequence of records that have several different key fields, then
 * one may want to sort it by one field without completely destroying
 * the ordering that one previously obtained from sorting it by a
 * different field. For example, sorting by last name and then by
 * first name.
 * 
 * sort() currently uses the introsort implementation created by Musser,
 * and sorts the entire range of data. This allows the efficiency of
 * using quick sort until it becomes inefficient at which point it
 * shifts to heap sort. Earlier versions of sort used the quick sort
 * algorithm.
 * 
 * Below is an example of using sort() on a vector. The sort algorithm
 * orders the container's contents in ascending order, as defined by
 * the "less than" (<) operator as applied to the vector elements.
 */

int main() {
  vector<int> aVector{10, 3, 7, 15, -5, 120, 42};

  for (auto i : aVector)
    cout << i << " ";
  cout << endl;

  sort(aVector.begin(), aVector.end());

  for (auto i : aVector)
    cout << i << " ";
  cout << endl;

  sort(aVector.begin(), aVector.end(), greater<>());

  for (auto i : aVector)
    cout << i << " ";
  cout << endl;

  return 0;
}

