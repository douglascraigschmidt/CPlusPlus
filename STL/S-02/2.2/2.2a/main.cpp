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
 * different data types without separate code for each of them. For a
 * similar operation on several kinds of data types, therefore, it
 * isn’t always as efficient to write several different versions by
 * overloading a function; writing one template function will take
 * care of many cases where overloaded functions might be written.
 * Thus, this template member function generalizes all the overloaded
 * "plus()" methods above.
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
  int i = 5, j = 6, k;
  long l = 10, m = 5, n;
  double a = 10.5, b = 5.5, d;

  k = plus(i, j);
  n = plus(l, m);
  d = plus(a, b);

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
