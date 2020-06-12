#include <iostream>
using namespace std;

class example_class {
public:
  explicit example_class (int y): x(y) {}

  bool firstFunc (int i) const {
    return i > x;
  }

private:
  int x;
};

/**
 * This example shows now ptrMemFunc can be a pointer to a member
 * function of class example_class.
 */
int main () {
  // Declare a member function pointer.
  bool (example_class::*ptrMemFunc)(int) const
    = &example_class::firstFunc;

  example_class array (10);

  if ((array.*ptrMemFunc)(11))
    cout << "the pointer member function is true because 11 is great than 10" << endl;
}       
