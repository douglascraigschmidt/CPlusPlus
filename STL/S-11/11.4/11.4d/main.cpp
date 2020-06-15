#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

/**
 * This (overly specific ;-)) functor is used below to showcase
 * remove_copy_if().
 */
struct twenty : unary_function<int, int> {
	bool operator () (int x) const { return x == 20; }
};

/**
 * The remove_copy_if() algorithm copies the values of the elements in
 * the range [first,last) to the range positions beginning at result,
 * except for the elements that compare equal to a given predicate,
 * which are not copied.  Here's an example of remove_copy_if().
 */
int main () {
  int a[] = {10, 20, 30, 30, 20, 10, 10, 20};          
  vector<int> myVect;

  cout << "array a[] originally contains:";
  copy (begin(a), end(a), ostream_iterator<int> (cout, " "));
  cout << endl;  

  remove_copy_if (begin(a),
                  end(a),
                  back_inserter(myVect), 
                  twenty ());

  cout << "After removing 20's myVect contains:";
  copy (myVect.begin(), myVect.end(), ostream_iterator<int> (cout, " "));
  cout << endl;  

  myVect.resize(0);

  // Remove everything that's not a 10!
  auto nend = remove_copy_if (begin(a),
                              end(a),
                              back_inserter(myVect),
                              not_fn(bind(equal_to<>(), placeholders::_1, 10)));

  cout << "After removing every thing that's not a 10 myVect contains:";
  copy (myVect.begin(), myVect.end(), ostream_iterator<int> (cout, " "));
  cout << endl;  

  // Copy all the 10's
  auto nnend = copy_if (begin(a),
                        end(a),
                        begin(a),
                        [](auto i) { return i == 10; });

  cout << "After copying every thing that's a 10 a[] contains:";
  copy (begin(a), nnend, ostream_iterator<int> (cout, " "));
  cout << endl;  
  return 0;
}
