#include <iostream>
#include <algorithm>

#include "stack.h"

using namespace std;

/**
 * This example demonstrates the use of C++ exceptions to report errors
 * with our stack ADT.
 */
int main() {
  stack<int> s1(10);
  auto item = 0;

  try {
    for (;;)
      s1.push(item++);
  } catch (stack<int>::overflow &ex) {
    cout << ex.what() << endl;
  }

  try {
    for (;;) {
      int i;
      cout << "top item = " << s1.top() << endl;
      s1.pop();
    }
  } catch (stack<int>::underflow &ex) {
    cout << ex.what() << endl;
  }

  // Termination is handled automatically.

  return 0;
}
