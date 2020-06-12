#include <iostream>
// using namespace std;

/**
 * In many ways, templates work like preprocessor macros, replacing
 * the templated variable with the given type. However, there are many
 * differences between a macro and a template, as shown in the example
 * below.
 */

/** 
 * This macro returns the smaller of two parameters.
 */ 
#define MIN(i, j) (((i) < (j)) ? (i) : (j))

/** 
 * This template function returns the smaller of two parameters.
 */ 
template<typename T>
T min(const T &i, const T &j) {
  return i < j ? i : j;
}

/**
 * Here are some problems with macros:
 *
 * . The C++ compiler does not verify that the macro parameters are of
 *   compatible types because macros don't do type checking.
 *
 * . In the macro version, the i and j parameters are evaluated twice, e.g.,
 * 
 *   int a = 10, b = 20;
 *   int c = min (a++, b++);
 *   int d = MIN(a++, b++); => (((a++) < (b++)) ? (a++) : (b++))
 * 
 * . Macros are expanded by the preprocessor, so, compiler error
 *   messages will refer to the expanded macro, rather than the macro
 *   definition itself. Also, the macro will show up in expanded form
 *   during debugging so programmers can't see its code during
 *   debugging, e.g., debuggers can't set breakpoints in macros.
 *
 * The function below demonstrates the problems with macros.
 */
int main() {
    int a = 10, b = 20;

    std::cout << "min = " << min(a++, b++) << std::endl;
    std::cout << "MIN = " << MIN(a++, b++) << std::endl;

    std::cout << "a = " << a << " b = " << b << std::endl;

    return 0;
}

