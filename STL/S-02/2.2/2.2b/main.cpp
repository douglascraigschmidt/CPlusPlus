#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)   {
     return a + b;
}

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
