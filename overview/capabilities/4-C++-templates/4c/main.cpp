#include <iostream>
#include <algorithm>

#include "stack.h"
#include "throw_exception.h"

using namespace std;

int main() {
  try {
      // Multiple stacks that are created automatically.
      stack<throw_exception> s1(3), s2(10);

      cout << "begin copy constructor" << endl;
      stack<throw_exception> s3(s2);
      cout << "end copy constructor" << endl;

      cout << "begin move constructor" << endl;
      stack<throw_exception> s4(std::move(s2));
      cout << "end move constructor" << endl;

      int item = 0;

      cout << "begin push()" << endl;
      while (!s1.full())
          s1.push(item++);
      cout << "end push()" << endl;

      cout << "begin pop()" << endl;
      while (!s1.empty()) {
          cout << "top item = " << s1.top() << endl;
          s1.pop();
      }
      cout << "end pop()" << endl;

      cout << "begin emplace()" << endl;
      while (!s1.full())
          s1.emplace(item++);
      cout << "end emplace()" << endl;

      cout << "begin pop()" << endl;
      while (!s1.empty()) {
          cout << "top item = " << s1.top() << endl;
          s1.pop();
      }
      cout << "end pop()" << endl;

      cout << "begin copy assignment operator" << endl;
      s1 = s2; // No aliasing problem with assignment
      cout << "end copy assignment operator" << endl;

      cout << "begin move assignment operator" << endl;
      s1 = std::move(s2); // move assignment.
      cout << "end move assignment operator" << endl;

      // Termination is handled automatically.
  } catch (std::out_of_range &ex) {
      cout << "caught out of range error" << endl;
  }

  return 0;
}
