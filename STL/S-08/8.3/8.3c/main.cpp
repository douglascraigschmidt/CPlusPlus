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
 * minus<type>()            Binary      Subtracts supplied parameters (param1 - param2)
 * 
 * multiplies<type>()       Binary      Multiplies supplied parameters (param1 * param2)
 * 
 * divides<type>()          Binary      Divides supplied parameters (param1 / param2)
 * 
 * modulus<type>()          Binary      Remainder of parameters (param1 % param2)
 */

/**
 * Forward declarations.
 */
template<typename InputIterator>
static void demonstrate_functors(InputIterator first, InputIterator last);
template<typename InputIterator>
static void demonstrate_lambdas(InputIterator first, InputIterator last);

/*
 * This example uses the arithmetic functors with the STL transform()
 * algorithm.
 */
int main() {
  // Use the default less<> functor to order set in ascending order.
  set<float> aSet{5.5, 1.1, 3.3, 4.4, 2.2};

  demonstrate_functors(aSet.begin(), aSet.end());
  demonstrate_lambdas(aSet.begin(), aSet.end());

  // Use a functor to order set in descending order.
  set<float, std::greater<>> dSet{5.5, 1.1, 3.3, 4.4, 2.2};

  demonstrate_functors(dSet.begin(), dSet.end());
  demonstrate_lambdas(dSet.begin(), dSet.end());

  return 0;
}

template<typename InputIterator>
static void
demonstrate_functors(InputIterator first, InputIterator last) {
  vector<float> aVect;

  copy (first,
        last,
        ostream_iterator<float> (cout, " "));
  cout << endl;

  // Multiple all float in the vector by themselves (i.e., double
  // themselves) and store them back into the vector.
  transform(first, last,
            first,
            back_inserter(aVect),
            multiplies<>());

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;

  // Divide all floats in the vector by 3 and store them back into the vector.
  transform(first, last,
            // This works because aVect retains is values from earlier transform().
            aVect.begin(),
            bind(divides<float>(), placeholders::_1, 3.0));

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;
}

template<typename InputIterator>
static void
demonstrate_lambdas(InputIterator first, InputIterator last) {
  vector<float> aVect;

  copy (first,
        last,
        ostream_iterator<float> (cout, " "));
  cout << endl;

  // Multiple all float in the vector by themselves (i.e., double
  // themselves) and store them back into the vector.
  transform(first, last,
            first,
            back_inserter(aVect),
            [](auto a, auto b) { return a * b; });

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;

  // Divide all floats in vector by 3 and store them back into vector.
  transform(first, last,
            // aVect retains its values from earlier transform().
            aVect.begin(),
            [](auto a) { return a / 3.0; });

  copy (aVect.begin (),
        aVect.end (),
        ostream_iterator<float> (cout, " "));
  cout << endl;
}

