#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

/**
 * The ptr_fun() adapters take a pointer to a function and turn it
 * into a functor. They are not designed for a function that takes no
 * arguments; they are for both unary functions and binary functions.
 * 
 * Here is an example of using a pointer to a class member
 * function. Define ptrFunc as a pointer to a non class member
 * function taking a single integer argument and returning a bool:
 * 
 * bool (*ptrFunc)(int);
 *  
 * The value of ptrFunc becomes an actual function address to the CPU:
 */
bool isGreatThanTen (int i) {
  return i > 10;
}

int main () {
  bool (*ptrToFunc)(int) = &isGreatThanTen;

  if (ptrToFunc(11))
    std::cout << "ptrToFunc (11) true" << endl;

  return 0 ;
}
