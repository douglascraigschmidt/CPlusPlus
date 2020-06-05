#include <iostream>
#include <algorithm>
#include <stdexcept>

#include "stack.h"
#include "throw_exception.h"

using namespace std;

int main() {
  try {
      // Multiple stacks that are created automatically.
      stack<throw_exception> s1(3), s2(10);
      stack<throw_exception> s3(s2);
      stack<throw_exception> s4(std::move(s2));

      int item = 0;

      while (!s1.full())
          s1.push(item++);

      while (!s1.empty()) {
          cout << "top item = " << s1.top() << endl;
          s1.pop();
      }

      while (!s1.full())
          s1.emplace(item++);

      while (!s1.empty()) {
          cout << "top item = " << s1.top() << endl;
          s1.pop();
      }

      s1 = s2; // No aliasing problem with assignment
      s1 = std::move(s2); // move assignment.
      // Termination is handled automatically.
  } catch (std::out_of_range &ex) {
      cout << "caught out of range error" << endl;
  }

  return 0;
}
