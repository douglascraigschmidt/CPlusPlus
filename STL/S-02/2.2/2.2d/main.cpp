#include <iostream>
using namespace std;

/**
 * A function template can be overloaded either by a non-template
 * function or by another function template.
 * 
 * If a program invokes an overloaded function template, the compiler
 * will try to deduce its template arguments and check its explicitly
 * declared template arguments. If successful, it will instantiate a
 * function template specialization, then add this specialization to
 * the set of candidate functions used in overload resolution.
 *
 * The compiler proceeds with overload resolution, choosing the most
 * appropriate function from the set of candidate functions. Non-
 * template functions take precedence over template functions (which
 * forms the basis for so-called "template specialization" as we'll
 * discuss later).
 */

/**
 * A template function.
 */
template<typename T> 
void f(T x, T y) { 
  cout << "Template" << endl; 
}

/**
 * An overloaded non-template function.
 */
void f(int w, int z) { 
  cout << "Non-template" << endl; 
}

/*
void f(char w, char z) {
    cout << "Non-template (pt2)" << endl;
} */

/**
 * This example demonstrates the use of template functions and
 * non-template functions.
 */
int main () {
  f(1, 2);
  f('a', 'b');
  f(1, 'b');
  
  return 0;
}
