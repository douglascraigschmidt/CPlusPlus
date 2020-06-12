#include <iostream>
#include <algorithm>
#include <string>

#include "stack.h"

using namespace std;

/**
 * This example of the stack shows how to implement it as a C++ ADT.
 * https://en.wikipedia.org/wiki/Abstract_data_type.  It also demonstrates
 * the C++ "Rule of 5", as well as demonstrates the difference between copy
 * semantics and move semantics for constructors and assignment operators.
 */
int main() {
  // Multiple stacks that are created automatically.
  cout << "begin constructors" << endl;  
  stack s1(1), s2(0);
  cout << "end constructors" << endl;

  auto item = 0;

  cout << "begin push(const T&)" << endl;
  while (!s1.full()) {
    simple_string s = std::to_string(item++).c_str();
    s1.push(s);
  }
  cout << "end push(const T&)" << endl;

  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }

  cout << "begin push(T &&)" << endl;
  while (!s1.full())
    s1.push(std::to_string(item++).c_str());
  cout << "end push(T &&)" << endl;

  cout << "begin copy constructor" << endl;
  stack s3(s1);
  cout << "end copy constructor" << endl;

  cout << "begin move constructor" << endl;
  stack s4(std::move(s3));
  cout << "end move constructor" << endl;

  cout << "begin copy assignment operator" << endl;  
  s2 = s1; // No aliasing problem with assignment
  cout << "end copy assignment operator" << endl;

  cout << "begin move assignment operator" << endl;
  s3 = std::move(s2); // move assignment.
  cout << "end copy assignment operator" << endl;

  while (!s1.empty()) {
    cout << "top item = " << s1.top() << endl;
    s1.pop();
  }

  cout << "begin destructors" << endl;
  // Termination is handled automatically.
}
