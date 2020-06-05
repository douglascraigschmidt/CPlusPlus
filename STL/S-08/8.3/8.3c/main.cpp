#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

/**
 * Arithmetic functors are (mostly) binary operations that return the
 * sum, difference, product, or division of the first argument and the
 * second.  Binary means they take two arguments and unary means they
 * take one argument.
 * 
 * Functor                  Type        Result
 * 
 * negate<type>()           Unary       Negates supplied parameter (-param)
 * 
 * plus<type>()             Binary      Adds supplied parameters (param1 + param2)
 * 
 * minus<type>()            Binary      Subtracts supplied parameters (param1 ¡V param2)
 * 
 * multiplies<type>()       Binary      Multiplies supplied parameters (param1 * param2)
 * 
 * divides<type>()          Binary      Divides supplied parameters (param1 / param2)
 * 
 * modulus<type>()          Binary      Remainder of parameters (param1 % param2)
 *  
 * This example uses the arithmetic functors with the STL transform()
 * algorithm.
 */
int main() {
  // Use a functor to order set in descending order.
  set<float, std::greater<>> aSet{5.5, 1.1, 3.3, 4.4, 2.2};
  vector<float> aVect;

  copy (aSet.begin (),
        aSet.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;

  // Multiple all float in the vector by themselves (i.e., double
  // themselves) and store them back into the vector.
  transform(aSet.begin(), aSet.end(),
            aSet.begin(),
            back_inserter(aVect),
            multiplies<>());

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;

  // Divide all floats in the vector by 3 and store them back into the vector.
  transform(aSet.begin(), aSet.end(),
            // This works because aVect retains is values from earlier transform().
            aVect.begin(),
            bind2nd(divides<float>(), 3.0));

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;

  return 0;
}
