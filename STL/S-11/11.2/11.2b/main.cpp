#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Here is an example using the five parameter version of transform(),
 * along with copy() and generate_n().
*/
int main() {
  srand(time(nullptr));

  vector<int> v;

  // generate_n() fills the vector with data. The vector is empty, but
  // the back_inserter() ensures that when generate_n() writes to the
  // output iterator it adds it to the end of the vector. A function
  // pointer to rand() makes a suitable functor!
  generate_n(back_inserter(v), 10, rand);

  vector<int> v2(10, 20);

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  // The transform() does the equivalent of v[i] = v[i] % v2[i]; for
  // each v[i] in v. The first 3 parameters are the 2 input ranges --
  // the second input range is assumed to be at least as large as the
  // first. The fourth parameter is the output iterator. In this case
  // it's safe to use a normal iterator into the container since we
  // know exactly how many elements will need to be written. The fifth
  // parameter is the binary operation performed.
  transform(v.begin(), v.end(),
            v2.begin(),
            v.begin(),
            modulus<>() );
/*
  // Could also use this four-param version of transform():
  transform(v.begin(), v.end(),
            v.begin(),
            [](auto i) { return i % 20; });
            */

  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  sort(v.begin(), v.end(), greater<>() );
  copy(v.begin(), v.end(), ostream_iterator<int>( cout," "));
  cout << endl;

  return 0;
} 

#pragma clang diagnostic pop