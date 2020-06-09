#include <iostream>

/**
 * A template function with three different type parameters.
 */
template <typename R, typename T, typename U>
R max(T a, U b) {
    return a < b ? b : a;
}

/**
 * It's possible to add template parameters that aren't in the
 * function call list. If that is done, these parameters must be
 * placed before any parameters that are in both lists, and a program
 * invoking the function must specify all the arguments up to the last
 * argument datatype that cannot be determined from the function call
 * parameters. For example in this template function the datatypes T
 * and U can be determined when the function is called. But the return
 * datatype, R, cannot. Any program using this function must provide
 * the return datatype and optionally can provide all datatypes.
 */
int main () {
  // Must provide return datatype
  auto d = max<double>(5.5, 2);

  // can provide all datatypes (though int is optional).
  int i = max<int, char, char>('a', 'b');

  std::cout << d << std::endl;
  std::cout << i << std::endl;
  
  return 0;
}
