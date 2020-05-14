#include <iostream>
using namespace std;

template <typename R, typename T, typename U>
R max(T a, U b) {
    return a<b ? b: a;
}

int main () {
  // must provide return datatype
  double d = max<double>(5.5, 2);

  // can provide all datatypes
  int i = max<int, char, char>('a', 'b');

  cout << d << endl;
  cout << i << endl;
  
  return 0;
}
