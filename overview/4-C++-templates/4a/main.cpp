#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "stack.h"

using namespace std;

int main() {
  try {
    // Multiple stacks that are created automatically.
    stack<int> s1(10), s2(100);
    int item = 0;

    while (!s1.full())
      s1.push(item++);

    while (!s1.empty()) {
      cout << "top item = " << s1.top() << endl;
      s1.pop();
    }

    s1 = s2; // No aliasing problem with copy assignment
    // s1.top_ = 10; // Access problem caught at compile-time!
    // Termination is handled automatically.
  } catch (std::out_of_range &ex) {
    cout << "caught out_of_range exception" << endl;
  }

  return 0;
}
