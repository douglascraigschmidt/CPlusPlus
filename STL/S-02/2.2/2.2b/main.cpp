#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)   {
     return a + b;
}

/**
 * In the case of add() where only one generic type T is used as a
 * parameter for add(), the compiler can automatically determine which
 * data type to instantiate the function for without having to
 * explicitly specify the datatype within angle brackets (like we have
 * done before specifying <int> and <long>).  This is called argument
 * deduction.
 */
int main () {
  int i = 5, j = 6, k;
  long l = 10, m = 5,  n;
  k = add (i, j);  
  n = add (l, m);

  // The following is a compile error!
  // add(i, l);
  cout << k << endl;
  cout << n << endl;
  return 0;
}
