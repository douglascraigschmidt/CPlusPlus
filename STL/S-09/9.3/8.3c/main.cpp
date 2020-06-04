#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <iterator>

using namespace std;

/**
 * Arithmetic functors are (mostly) binary operations that return the
 * sum, difference, product, or division of the first argument and the
 * second.  Binary means they take two arguments and unary means they
 * take one argument.
 * 
 * Functor	Type	Result
 * 
 * negate<type>()	Unary	Negates supplied parameter (-param)
 * 
 * plus<type>()	Binary	Adds supplied parameters (param1 + param2)
 * 
 * minus<type>()	Binary	Subtracts supplied parameters (param1 ¡V param2)
 * 
 * multiplies<type>()	Binary	Multiplies supplied parameters (param1 * param2)
 * 
 * divides<type>()	Binary	Divides supplied parameters (param1 / param2)
 * 
 * modulus<type>()	Binary	Remainder of parameters (param1 % param2)
 *  
 * This example uses the arithmetic functors with the STL transform()
 * algorithm.
 */
int main() {
  vector<float> aVect{1, 2, 3, 4, 5};

  // Multiple all float in the vector by themselves (i.e., double
  // themselves)
  transform(aVect.begin(),  aVect.end(),
            aVect.begin(),
            aVect.begin (),
            multiplies<>());

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, "\n"));

  // Divide all floats in the vector by 3
  transform(aVect.begin(), aVect.end(),
            aVect.begin (),
            bind2nd(divides<float>(), 3.0));

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, "\n"));

  return 0;
}
