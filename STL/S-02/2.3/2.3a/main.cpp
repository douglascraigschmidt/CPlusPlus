#include <iostream>
#include <iterator>
#include <set>
#include "type_wrapper.h"
#include "pair.h"

/**
 * This example shows the use of class templates and also demonstrates
 * the difference between pass-by-value and pass-by-reference
 * semantics for C++ parameters and return values.
 */
int main () {
  {
    type_wrapper<int> p1(10);
    type_wrapper<int> p2(20);

    // Chose "my_pair" rather than std::pair.
    my_pair::pair<type_wrapper<int>> i_pair(p1, p2);

    std::cout << "the max of "
              << p1 << " and "
              << p2 << " = "
              << i_pair.max()
              << std::endl;
  }

  // It's easy to switch from one type parameter to another.
  {
    double d1 = 100.4;
    double d2 = 200.8;

    // Again, chose "my_pair" rather than std::pair.
    my_pair::pair<double> d_pair(d1, d2);

    std::cout << "the max of "
              << d1 << " and "
              << d2 << " = "
              << d_pair.max()
              << std::endl;
  }

  return 0;
}
