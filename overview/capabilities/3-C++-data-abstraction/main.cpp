#include <iostream>
#include <algorithm>

#include "stack.h"

using namespace std;

int main() {
  // Multiple stacks that are created automatically.
  stack s1(10), s2(100), s3(s2), s4(std::move(s2));

  T item = 0;

  while (!s1.is_full())
    s1.push(item++);

  while (!s1.is_empty()) {
    T i;
    s1.top(i);

    cout << "top item = " << i << endl;

    s1.pop();
  }

  s3 = s2; // No aliasing problem with assignment

  s1 = std::move(s2); // move assignment.

  // s1.top_ = 10; // Access problem caught at compile-time!

  // Termination is handled automatically.
}
