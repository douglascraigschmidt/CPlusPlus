#include <functional>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
   using namespace std;

/**
 * An overly specific functor!
 */
struct IntGreaterThanThree
  : public unary_function<int, bool> {
  bool operator() (int x) const { return x > 3; }
};

/** 
 * Here is a simple example showing a user defined functor being used
 * with the not1() negator and the find_if() algorithm.
 */
int main() {
  vector<int> v{4, 1, 2, 8, 5, 7};

  auto itr = find_if (v.begin(),
                      v.end(),
                      not1(IntGreaterThanThree()));

  // auto itr = find_if (v.begin(), v.end(), not1(bind2nd(greater<int> (), 3)));

  copy (itr,
        v.end (),
        ostream_iterator<int> (cout, "\n"));

  return 0;
}
