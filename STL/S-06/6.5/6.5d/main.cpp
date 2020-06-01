#include <iterator>
#include <numeric>
#include <deque>
#include <iostream>
using namespace std;

int main () {
  int total = 0;
  deque<int> d{3,4,7,8};

  // stream the whole deque and a sum to cout

  copy(d.begin(),
       d.end() - 1,
       ostream_iterator<int>(cout," + "));

  cout << *(d.end() - 1) << " = " <<
    accumulate(d.begin(),
               d.end(),
               total) << endl;
  return 0;
}
