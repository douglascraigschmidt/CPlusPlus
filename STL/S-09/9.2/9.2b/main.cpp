#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-transparent-functors"
#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

/**
 * This example applies bind2nd(), bind(), and a C++ lambda function
 * with various STL algorithms.
 */
int main () {
  array<double, 5> my_array = {10.1, 20.2,
                               30.3, 40.4,
                               50.5};

  const auto factor = 33.3;

  // Multiply all the contents in my_array by the factor.
  transform(my_array.begin(), my_array.end(),
            my_array.begin(),
            bind2nd(multiplies<double>(), factor));

  copy(my_array.begin(),
       my_array.end(),
       ostream_iterator<double> (cout, " "));
  cout << endl;

  auto value = 1000.2;

  // Count how many values are greater than value.
  auto n = count_if(my_array.begin(),
                    my_array.end(),
                    bind(greater<>(), placeholders::_1, value));

  cout << "number of elements greater than "
       << value
       << " = "
       << n 
       << endl;

  value = 1200.4;
  // Find the *last* element that's greater than value.
  auto i = find_if(my_array.rbegin(),
                   my_array.rend(),
                   [value](auto f) { return f > value; });

  if (i != my_array.rend())
    cout << "the last element greater than "
         << value
         << " is "
         << *i
         << endl;

  return 0;
}

#pragma clang diagnostic pop
