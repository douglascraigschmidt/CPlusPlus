#include <iostream>
#include <algorithm>

#include "stack.h"

using namespace std;

int main() {
  // Multiple stacks that are created automatically.
  stack s1(10), s2(100), s3;

  auto item = 0;

  while (!s1.full())
    s1.push(item++);

  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }

  s3 = s1; // No aliasing problem with assignment

  // s1.top_ = 10; // Access problem caught at compile-time!

  // Termination is handled automatically.
}
