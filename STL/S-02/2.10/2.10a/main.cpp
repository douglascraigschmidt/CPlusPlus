#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

/**
 * This is the "base" for the template recursion.
 */
template<typename T>
T adder(T v) {
  std::cout << "(" << __PRETTY_FUNCTION__ << ")\n";

  return v;
}

/**
 * This function demonstrates variadic templates.
 */
template<typename T, typename... Args>
T adder(T first, Args... args) {
  std::cout << __PRETTY_FUNCTION__ << "\n";

  return first + adder(args...);
}

/**
 * Demonstrate the use of variadic template functions!
 */
int main() {
  auto sum = adder(1, 4, 2, 3, 8, 7);

  cout << "sum = " << sum << endl;

  std::string s1 = "C++", s2 = " ", s3 = "is", s4 = " ", s5 = "cool!";
  auto string_sum = adder(s1, s2, s3, s4, s5);
  
  cout << "string sum = " << string_sum << endl;

  return 0;
}
