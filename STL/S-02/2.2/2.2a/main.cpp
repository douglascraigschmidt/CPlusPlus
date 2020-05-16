#include <iostream>

int plus(int a, int b) {
  return a + b;
}

long plus(long a, long b) {
  return a + b;
}

double plus(double a, double b) {
  return a + b;
}

template <typename T>
T add(T a, T b)   {
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

  k = add<int> (i, j);  
  n = add<long> (l, m);
  d = add<double> (a, b);

  std::cout << k << std::endl;
  std::cout << n << std::endl;
  std::cout << d << std::endl;
  return 0;
}
