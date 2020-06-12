#include <iostream>

#include "atomic_op.h"

using namespace std;

int main() {
  atomic_op<int> ai(10);
  atomic_op<double> ad(10.5);

  ++ai;
  --ai;
  --ai;
  ++ad;

  int aii(ai);
  double add(ad);

  cout << int(ai) << endl;
  cout << double(ad) << endl;
  cout << aii << endl;
  cout << add << endl;

  return 0;
}
