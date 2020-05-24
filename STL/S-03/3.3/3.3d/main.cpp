#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

/**
 * Key characteristics of vectors:
 *
 * . Random access to elements
 * . Constant time insertion and removal of elements at end
 * . Linear time insertion of elements at beginning or middle because
 *   other elements have to be moved  
 * . Number of elements can vary dynamically
 * . Simplest and most efficient type of STL container
 * . Member function reserve() can pre-allocate all memory needed
 * . Assignment,  copy constructor, and destructor supported 
 *
 * A vector can be used like an ordinary C array, except that vector
 * eliminates the chore of managing dynamic memory allocation.  
 *
 * This example shows how to create and use a vector that contains
 * another vector inside it, i.e., a vector-of-vectors similar (but
 * not identical) to C/C++ 2-dimensional array.
 */
int main() {
  vector<vector<int>> myVec2D;     	// create 2D int vector
  vector<int> oneVec, twoVec;		// create two int vectors

  oneVec.push_back(1); oneVec.push_back(2); oneVec.push_back(3);
  twoVec.push_back(4); twoVec.push_back(5); twoVec.push_back(6);

  myVec2D.push_back(oneVec); 
  myVec2D.push_back(twoVec);

  cout << endl << "Using Iterator:" << endl;

  for (vector<vector<int>>::iterator iter2D = myVec2D.begin();
      iter2D != myVec2D.end();
      ++iter2D)
    for(vector<int>::iterator iter = iter2D->begin();
        iter != iter2D->end(); ++iter)
      cout << *iter << endl;

  cout << endl << "Using subscript operators:" << endl;

  for (size_t i = 0; i < myVec2D.size(); ++i)
    for (size_t j = 0; j < myVec2D[i].size(); ++j)
      cout << myVec2D[i][j] << endl;

  cout << endl << "Using range-based for loop:" << endl;

  for (const auto &inner_vec : myVec2D)
    for (auto i : inner_vec)
      cout << i << endl;

  return 0;
}

