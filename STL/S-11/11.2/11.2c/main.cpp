#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#include <iostream>
#include <functional>
#include <random>
#include <vector>
#include <algorithm> 
#include <numeric> 
#include <iterator>
#include <ctime>

using namespace std; 

/**
 * This example uses several STL algorithm functions to work with the
 * elements of two vectors, each holding 10 integers. It also uses the
 * plus() functor with the transform() algorithm to add the elements.
 */
int main() {
  vector<int> v1(10), v2(10);

  fill(v1.begin(), v1.end(), 1);
  partial_sum(v1.begin(), v1.end(), v1.begin());
  shuffle(v1.begin(), v1.end(),
          default_random_engine(time(nullptr)));

  copy(v1.begin(),v1.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  fill(v2.begin(), v2.end(), 2);
  partial_sum(v2.begin(), v2.end(), v2.begin());
  shuffle(v2.begin(), v2.end(),
          std::mt19937(std::random_device()()));

  copy(v2.begin(),v2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl;

  transform(v1.begin(), v1.end(),
            v2.begin(),
            v2.begin(),
            plus<>());

  copy(v2.begin(),v2.end(), ostream_iterator<int>(cout, " ")); 
  cout << endl;
  return 0;
} 


#pragma clang diagnostic pop