#include <iostream>
#include <stack>
using namespace std;

/**
 * A functor, or function object, is simply any object that can be
 * called as if it is a function. The C++ Standard Template Library
 * defines a few simple functors to do arithmetic and make relational
 * and logical comparisons.
 * 
 * To create an object that behaves just like a function, one only
 * need to provide a way to call this object by name using parentheses
 * and (optionally) pass arguments. Just create a class that overloads
 * the function call operator, which is simply a pair of parentheses:
 * '()'.
 *
 * Functors are STL's improvement over traditional C function pointers.
 * While you can still use regular function pointers with the correct
 * argument signature, STL's predefined functors offer some significant
 * benefits, such as the ability to optimize the functors via inline
 * method calls and/or the ability to maintain state within the
 * functor.
 *
 * Below is a simple (stateless) functor.
 */
class simple_function_object {
public:
  int operator()(int i) { return i; }
};

/**
 * The example below shows how we can call this function just like any
 * other function, only being a class it can hold data as well as
 * several functions within itself (not shown in this example).
 */
int main() {
  // instantiate the functor
  simple_function_object aFunctor;

  // calls operator '()' of class 'function_object'
  cout << aFunctor(5) << endl;

  // also calls operator '()' of class 'function_object'
  cout << aFunctor.operator()(2) << endl;

  return 0;
}
