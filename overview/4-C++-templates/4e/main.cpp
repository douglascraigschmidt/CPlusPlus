#include <iostream>
#include <algorithm>

#include "stack.h"

#include "simple_string.h"

using namespace std;

int main() {
  const int STACK_SIZE = 3;

  // Multiple stacks that are created automatically.
  stack<simple_string, STACK_SIZE> s1;

  cout << "begin copy constructor" << endl;
  stack<simple_string, STACK_SIZE> s2(s1);
  cout << "end copy constructor" << endl;

  int item = 0;

  cout << "begin push()" << endl;
  while (!s1.full())
    s1.push(std::to_string(item++).c_str());
  cout << "end push()" << endl;

  cout << "begin pop()" << endl;
  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }
  cout << "end pop()" << endl;

  cout << "begin emplace()" << endl;
  while (!s1.full())
    s1.emplace(std::to_string(item++).c_str());
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

  // Termination is handled automatically.
  cout << "calling destructors" << endl;

  return 0;
}
