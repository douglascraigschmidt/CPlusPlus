#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iostream>
using namespace std;

/**
 * A negator adapter can be used to store the opposite result of a
 * functor.
 *
 * Negater	Result
 * not1(Op)	Negates the result of unary 'Op'
 * not2(Op)	Negates result of binary 'Op'
 * 
 * To see how these negators work, we'll create our own template for
 * simple boolean functor that will check if a value is an odd number
 * and it will return true or false. This template takes only one
 * argument, so it is unary.
 */

template<typename T>
struct is_odd : unary_function<T, bool> {
  bool operator() (T number) const {
    return number % 2 != 0;
  }
};
  
/**
 * We now use these templates with a STL algorithm named
 * remove_copy_if() and a STL functor not1().  This takes 4 arguments:
 * start copying from here, stop here, and the true/false function to
 * use to determine whether to copy the argument into the result
 * output iterator.
 */
int main() {
  vector<int> vector1{1, 2, 3, 4};
  vector<int> vector2;

  // Remove odd numbers via a functor.
  remove_copy_if(vector1.begin(), vector1.end(),
                 back_inserter(vector2),
                 is_odd<int>());

  copy(vector2.begin(),
       vector2.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  vector<int> vector3;
  // Remove even numbers via a negator.
  remove_copy_if(vector1.begin(), vector1.end(),
                 back_inserter(vector3),
                 not1(is_odd<int>()));

  copy(vector3.begin(),
       vector3.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;

  // Clear the vector.
  vector3.resize(0);

  // Copy odd numbers using a C++ lambda function.
  copy_if(vector1.begin(),
          vector1.end(),
          back_inserter(vector3),
          [](int number)  {
            return number % 2 != 0;
          });

  copy(vector3.begin(),
       vector3.end(),
       ostream_iterator<int>(cout, " "));
  cout << endl;    

  return 0;
}
