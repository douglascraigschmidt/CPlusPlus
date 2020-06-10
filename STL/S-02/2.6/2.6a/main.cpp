#include <iostream>  
using namespace std;

/**
 * Three types of parameters can be used with templates:
 *
 * . Typed template parameters  
 * . Non-type template parameters  
 * . Template template parameters 
 *
 * Templates can have regular typed parameters, similar to those found
 * in functions. Typed template parameters are preceded by the keyword
 * typename or class.
 * 
 * Templates can also have regular parameters - these are called "non
 * type" template parameters.
 * 
 * The syntax of a non-typed template parameter is the same as a
 * declaration of one of the following types:
 *
 * . integral or enumeration  
 * . pointer to object or pointer to function 
 * . reference to object or reference to function 
 * . pointer to member.  
 * 
 * A program may qualify a non-type template parameter with const or
 * volatile.
 *
 * Non-type template parameters have restrictions: they must be
 * integral values, enumerations, or instance pointers with external
 * linkage. They can't be string literals nor global pointers since
 * both have internal linkage. Nor can they be floating point,
 * typename, or void type.
 *
 * Non-type template parameters are not lvalues, i.e., they are
 * simply "plain old data" (POD).
 */

#include "memblock.h"

/**
 * A function can also define non-type function template parameters.
 */
template <typename T, int V>
T add_const_n (const T &n) {
  return n + V;
}

int main () {
  memblock <int, 5> my_ints;
  memblock <double, 15> my_floats;

  my_ints.setmem (0,100); 
  my_floats.setmem (3,3.1416); 

  cout << my_ints.getmem(0) << endl; 
  cout << my_floats.getmem(3) << endl;

  auto i = add_const_n<int, 6> (10);
  cout << "i = " << i << endl;
  return 0; 
} 
