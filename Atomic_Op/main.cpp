#include <iostream>

#include "atomic_op.h"

using namespace std;

int main() {
  atomic_op<int> ai(10);
  atomic_op<double> ad(10.5);

  ++ai;
  ++ad;

  cout << int(ai) << endl;
  cout << double(ad) << endl;

  return 0;
}
