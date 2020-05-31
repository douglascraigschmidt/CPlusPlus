#include <stdio.h>
#include <algorithm>

#include "stack.h"

int main() {
  // Multiple stacks that are created automatically.
  stack s1(10), s2(100), s3;

  T item = 0;

  while (!s1.is_full())
    s1.push(item++);

  while (!s1.is_empty()) {
    T i;
    s1.top(i);
    printf("top item = %d\n", i);
    s1.pop();
  }

  s3 = s2; // No aliasing problem with assignment

  s1 = std::move(s1); // move assignment.

  // s1.top_ = 10; // Access problem caught at compile-time!

  // Termination is handled automatically.
}
