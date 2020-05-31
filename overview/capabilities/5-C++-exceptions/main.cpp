#include <iostream>
#include <algorithm>

#include "stack.h"

using namespace std;

int main() {
  stack<int> s1(10);

  int item = 0;

  try {
    for (;;)
      s1.push(item++);
  } catch (stack<int>::overflow &ex) {
    cout << ex.what() << endl;
  }

  try {
    for (;;) {
      int i;
      s1.top(i);
      printf("top item = %d\n", i);
      s1.pop();
    }
  } catch (stack<int>::underflow &ex) {
    cout << ex.what() << endl;
  }

  // Termination is handled automatically.

  return 0;
}
