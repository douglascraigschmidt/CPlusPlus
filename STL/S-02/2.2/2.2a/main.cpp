#include <iostream>

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
 * different data types without duplicating separate code for each of
 * them, thereby supporting the "Don't Repeat Yourself" (DRY)
 * principle.  For similar operations on several kinds of data types,
 * it isn’t always efficient to write several different versions by
 * overloading a function. Instead, writing one template function will
 * take care of many cases where overloaded functions might be
 * written.  This template member function therefore generalizes all
 * the overloaded "plus()" methods above.
 */
template <typename T>
T add(T a, T b) {
  return a + b;
}

/**
 * This example compares/contrasts the use of non-template functions
 * and template functions.
 */
int main () {
  int i = 5, j = 6;
  long l = 10, m = 5;
  double a = 10.5, b = 5.5;

  int k = plus(i, j);
  long n = plus(l, m);
  double d = plus(a, b);

  std::cout << k << std::endl;
  std::cout << n << std::endl;
  std::cout << d << std::endl;

  // Use explicit template types.
  k = add<int> (i, j);  
  n = add<long> (l, m);
  d = add<double> (a, b);

  std::cout << k << std::endl;
  std::cout << n << std::endl;
  std::cout << d << std::endl;
  
  return 0;
}
