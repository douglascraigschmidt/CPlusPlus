#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * This example applies bind2nd() with various STL algorithms.
 */
int main () {
  vector<double>  myVector{10.1, 20.2, 30.3, 40.4, 50.5};

  double factor = 33.3;

  transform(myVector.begin(), myVector.end(),
            myVector.begin(),
            bind2nd(multiplies<double>(), factor) );

  copy(myVector.begin(),
       myVector.end(),
       ostream_iterator<double> (cout, " "));

  cout << endl;

  auto n = count_if(myVector.begin(),
                    myVector.end(),
                    bind2nd(greater<float>(), 1000.2));

  cout << "number of elements greater than 1000.2 = " 
       << n 
       << endl;

  return 0;
}
