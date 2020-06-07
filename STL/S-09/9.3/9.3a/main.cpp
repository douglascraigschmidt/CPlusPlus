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
 * Negater     Result
 * not1(Op)    Negates the result of unary 'Op'
 * not2(Op)    Negates result of binary 'Op'
 * not_fn(Op)  Negates result of 'Op'
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
 * Forward declaration.
 */
template<typename T,
        template <typename ...> class sequential_container>
static void
print_results(const sequential_container<T> &container);

/**
 * We use these templates with a STL algorithm named remove_copy_if()
 * and STL functors not1()/not_fn().  These methods take 4 arguments:
 * start copying from here, stop here, and the true/false function to
 * use to determine whether to copy the argument into the result
 * output iterator.
 */
int main() {
  vector<int> vector1{1, 2, 3, 4};
  vector<int> vector2;

  // Remove even numbers via the not1() negator.
  remove_copy_if(vector1.begin(), vector1.end(),
                 back_inserter(vector2),
                 not1(is_odd<int>()));

  print_results(vector2);

  vector<int> vector3;
  // Remove even numbers via the not_fn() negator.
  remove_copy_if(vector1.begin(), vector1.end(),
                 back_inserter(vector3),
                 not_fn(is_odd<int>()));

  print_results(vector3);

  // Clear the vector.
  vector3.resize(0);

  // Copy odd numbers using a C++ lambda function.
  copy_if(vector1.begin(),
          vector1.end(),
          back_inserter(vector3),
          [](auto number)  {
            return number % 2 != 0;
          });

  print_results(vector3);

  return 0;
}

template<typename T,
         template <typename ...> class sequential_container>
static void
print_results(const sequential_container<T> &container) {
  copy(container.begin(),
       container.end(),
       ostream_iterator<T>(cout, " "));
  cout << endl;
}

