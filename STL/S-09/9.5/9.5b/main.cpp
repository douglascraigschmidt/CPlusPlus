#include <iostream>
using namespace std;

class example_class {
public:
  example_class (int y): x(y) {}

  bool firstFunc (int i) {
    return i > x;
  }

private:
  int x;
};

/**
 * This example shows now ptrFunc can be a pointer to a member
 * function of class example_class.
 */
int main () {
  // Declare a member function pointer.
  bool (example_class::*ptrFunc)(int);   

  ptrFunc = &example_class::firstFunc;  

  example_class array (10);

  if ((array.*ptrFunc)(11))
    cout << "the pointer member function is true" << endl;
}       
