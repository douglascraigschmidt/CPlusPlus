#include <iostream>

#include "atomic_op.h"

using namespace std;

int main() {
  atomic_op<int> ai(10);
  
  ++ai;
  
  cout << int(ai) << endl;
  return 0;
}
