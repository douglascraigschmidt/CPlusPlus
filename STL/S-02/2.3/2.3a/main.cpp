#include <iostream>
#include "simple_string.h"
#include "pair.h"

/**
 * This example shows the use of class templates and also demonstrates
 * the difference between pass-by-value and pass-by-reference
 * semantics for C++ parameters and return values.
 */
int main () {
  {
    simple_string s1("hello");
    simple_string s2("world");

    // Chose "my_pair" rather than std::pair.
    my_pair::pair<simple_string> string_pair(MOVE(s1), MOVE(s2));

    std::cout << "the max of "
              << s1 << " and "
              << s2 << " = "
              << string_pair.max()
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
