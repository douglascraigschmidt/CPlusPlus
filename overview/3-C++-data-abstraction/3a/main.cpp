#include <iostream>
#include <algorithm>

#include "stack.h"

using namespace std;

/**
 * This example of the stack shows how to implement it as a C++ ADT.
 * https://en.wikipedia.org/wiki/Abstract_data_type.  It also demonstrates
 * the C++ "Rule of 3".
 */
int main() {
  // Multiple stacks that are created automatically.
  stack s1(10), s2(100), s3, s4(s2);

  T item = 0;

  while (!s1.full())
    s1.push(item++);

  s3 = s1; // No aliasing problem with assignment

  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }

  while (!s3.empty()) {
    cout << "top item = " << s3.top() << endl;
    s3.pop();
  }

  // s1.top_ = 10; // Access problem caught at compile-time!

  // Termination is handled automatically.
}
