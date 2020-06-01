#include <iostream>
#include <iterator>
using namespace std;

int main() {
  ostream_iterator<int> oi(cout, ¡° ¡°);
  *oi++ = 6;
  *oi++ = 88;
  return 0;
}
