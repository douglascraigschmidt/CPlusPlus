#include <functional>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

/**
 * A negator adapter can be used to compute the opposite result of a
 * functor they encapsulate.
 *
 * Negater     Result
 * not1(Op)    Negates the result of unary 'Op'
 * not2(Op)    Negates result of binary 'Op'
 * not_fn(Op)  Negates result of either a unary or binary 'Op'
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
 * We use these template with STL algorithms remove_copy_if()/copy_if()
 * and STL functors not1()/not_fn().  The STL algorithms take 4 arguments:
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

  deque<int> deque1;
  // Remove even numbers via the not_fn() negator.
  remove_copy_if(vector1.begin(), vector1.end(),
                 back_inserter(deque1),
                 not_fn(is_odd<int>()));

  print_results(deque1);

  // Clear the deque.
  deque1.resize(0);

  // Copy odd numbers using a C++ generic lambda function.
  copy_if(vector1.begin(),
          vector1.end(),
          back_inserter(deque1),
          // This lambda function returns true if number is odd!
          [](auto number)  {
            return number % 2 != 0;
          });

  print_results(deque1);

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

