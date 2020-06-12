#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * This example applies bind2nd() and a C++ lambda function with
 * various STL algorithms.
 */
int main () {
  vector<double> myVector{10.1, 20.2, 30.3, 40.4, 50.5};

  const auto factor = 33.3;

  // Multiply all the contents in myVector by the factor.
  transform(myVector.begin(), myVector.end(),
            myVector.begin(),
            bind2nd(multiplies<double>(), factor));

  copy(myVector.begin(),
       myVector.end(),
       ostream_iterator<double> (cout, " "));
  cout << endl;

  auto value = 1000.2;

  // Count how many values are greater than value.
  auto n = count_if(myVector.begin(),
                    myVector.end(),
                    bind2nd(greater<float>(), value));

  cout << "number of elements greater than "
       << value
       << " = "
       << n 
       << endl;

  value = 1200.4;
  // Find the *last* element that's greater than value.
  auto i = find_if(myVector.rbegin(),
                   myVector.rend(),
                   [value](auto f) { return f > value; });

  if (i != myVector.rend())
    cout << "the last element greater than "
         << value
         << " is "
         << *i
         << endl;

  return 0;
}

#pragma clang diagnostic pop
