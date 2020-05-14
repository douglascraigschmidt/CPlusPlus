#include <iostream>
#include <iterator>
#include <set>
#include "type_wrapper.h"
using namespace std;

template <typename T>
class aPair {
public:
#if PASS_BY_VALUE==1
    aPair (T f, T s) {
        first = f;
        second = s;
    }
#else
    aPair(const T &f, const T &s)
            : first (f),
              second (s)
    {}
#endif /* PASS_BY_VALUE */

  T max();		

  T first; 
  T second;  
};

template <typename T>					 
T aPair<T>::max() {
  return first < second ? second : first;
}

int main () {
  type_wrapper<int> f1(10);
  type_wrapper<int> f2(20);

  aPair<type_wrapper<int>> myPair(f1, f2);

  cout << "the max of " << f1 << " and " << f2 << " = " << myPair.max() << endl;

  return 0;
}
