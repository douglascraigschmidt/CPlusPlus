#include <iostream>
using namespace std;

/**
 * This is a simple template function with a single type parameter.
 */
template <typename T>
T add(T a, T b) {
  return a + b;
}

/**
 * In the case of add() where only one generic type T is used as a
 * parameter for add(), the compiler can automatically determine which
 * data type to instantiate the function for without having to
 * explicitly specify the datatype within angle brackets (like we have
 * done before specifying <int> and <long>).  This selection process
 * is called "argument deduction".
 */
int main () {
  int i = 5, j = 6;
  long l = 10, m = 5;

  int k = add(i, j);
  long n = add(l, m);
  double d = add(10.5, 16.7);

  // The following is a compile error!
  // add(i, l);

  cout << k << endl;
  cout << n << endl;
  cout << d << endl;
  return 0;
}
