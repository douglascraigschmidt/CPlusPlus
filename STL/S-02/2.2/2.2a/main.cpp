#include <iostream>

/**
 * C++ is a "strongly-typed language", i.e. a program must declare all
 * variables with their datatypes before they are used. Strong typing
 * is great for ensuring that the correct amount of storage is used
 * for each variable and that only the correct operations can be
 * performed on its data. In addition, data type checking for each
 * variable prevents memory leaks and illegal operations that might
 * causes exceptions in a running program.
 *
 * However, one drawback of strong typing occurs when a program needs
 * to perform the same or a similar action on many types of variables.
 * Without having classes or OO technology, a language such as C, used
 * #define preprocessor directives to define variables and even small
 * functions without datatypes. Another way to perform such actions in
 * C uses void pointers since no datatype is explicitly involved.
 * Unfortunately, these work-arounds don’t operate in a datatype safe
 * manner – they just avoids the type checking that C or C++ provides.
 *
 * Moreover, neither of these options uses the power of modern OO
 * languages. Other techniques (such as making all such functions or
 * classes refer to Object or an Object reference) also don’t solve
 * the problem entirely. They are objected oriented, but still incur
 * the problem that the data type checking part of C++ is bypassed.
 * 
 * To preserve the power of C++’s datatype checking, another way is to
 * use many overloaded functions in a class, each having a different
 * type of data as input. The problem with this comes later when the
 * program needs to be enhanced, maintained, fixed, etc. Then the job
 * of keeping all of these functions in synch is a difficult one. Why
 * not have ONE function that takes one parameter of any datatype?
 * That capability is precisely a "function template" provides!
*/

/**
 * C++ has long supported overloaded functions, but these can be
 * tedious and error-prone to write, especially if the logic is the
 * same, but only the types differ.
 */
int plus(int a, int b) {
  return a + b;
}

long plus(long a, long b) {
  return a + b;
}

double plus(double a, double b) {
  return a + b;
}

/**
 * Function templates are special functions that can operate on
 * different data types without separate code for each of them. For a
 * similar operation on several kinds of data types, therefore, it
 * isn’t always as efficient to write several different versions by
 * overloading a function; writing one template function will take
 * care of many cases where overloaded functions might be written.
 */
template <typename T>
T add(T a, T b)   {
     return a + b;
}

/**
 * This example compares/contrasts the use of non-template functions
 * and template functions.
 */
int main () {
  int i = 5, j = 6, k;
  long l = 10, m = 5, n;
  double a = 10.5, b = 5.5, d;

  k = plus(i, j);
  n = plus(l, m);
  d = plus(a, b);

  std::cout << k << std::endl;
  std::cout << n << std::endl;
  std::cout << d << std::endl;

  // Note how types are explicitly provided here.
  k = add<int> (i, j);  
  n = add<long> (l, m);
  d = add<double> (a, b);

  std::cout << k << std::endl;
  std::cout << n << std::endl;
  std::cout << d << std::endl;
  return 0;
}
