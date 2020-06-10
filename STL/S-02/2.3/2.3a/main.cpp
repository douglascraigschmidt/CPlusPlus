#include <iostream>
#define MOVE std::move
#define PASS_BY_VALUE 1
#include "simple_string.h"
#include "pair.h"

using namespace std;

/**
 * This example shows the use of C++ class templates and also
 * demonstrates the difference between pass-by-value and
 * pass-by-reference semantics (including "copy" vs "move" semantics
 * and optimizations) for C++ parameters and return values.
 */
int main () {
  {
    simple_string s1("hello");
    simple_string s2("world");

    cout << "the max of "
         << s1 << " and "
         << s2 << " = ";

    // Chose "my_pair" rather than std::pair.
    my_pair::pair<simple_string> string_pair(MOVE(s1), MOVE(s2));

    cout << string_pair.max()
         << endl;
  }

  // It's easy to switch from one type parameter to another.
  {
    double d1 = 100.4;
    double d2 = 200.8;

    // Again, chose "my_pair" rather than std::pair.
    my_pair::pair<double> d_pair(d1, d2);

    cout << "the max of "
         << d1 << " and "
         << d2 << " = "
         << d_pair.max()
         << endl;
  }

  return 0;
}
