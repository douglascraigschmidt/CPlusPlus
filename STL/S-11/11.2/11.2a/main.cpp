#include <iostream>
#include <algorithm>
#include <functional>

#include "simple_string.h"

using namespace std;

/**
 * The following STL mutating algorithms perform filling, generating,
 * and transforming operations:
 * 
 * • fill() - change a range to all have the same given value. 
 * • fill_n() - change n items to all have the same given value. 
 * • generate() - change items in a range to be values produced by a
 *   function object. 
 * • generate_n() - change n items to be values produced by function
 *   object. 
 * • transform() - scans a range and for each use a function to
 *   generate a new object put in a second container, OR takes two
 *   intervals and applies a binary operation to items to generate a
 *   new container.
 * 
 * One example of a mutating algorithm is transform(), which has two
 * variants.  One variant requires four parameters: two iterators to
 * specify the input sequence, one to specify the output sequence, and
 * another to specify the unary transforming operation.  Another
 * variant requires five parameters: two iterators to specify the
 * first input range, one to specify the second input range, one to
 * specify the output sequence, and another to specify the binary
 * transforming operation.
 * 
 * The following code is an example of the four-parameter variant of
 * the transform() algorithm.
 */

/**
 * Return param str after lower casing it.
 */
static simple_string 
lowercase (simple_string str) {
  transform (str.cbegin(),
             str.cend(),
             str.begin(),
             [](auto c) { return isupper (c) ? tolower(c) : c; });
  return str;
}

/**
 * Use transform() to lower case an upper case string.
 */
int main () {
  simple_string s ("HELLO");
  cout << s << endl;
  s = lowercase (s); // (std::move(s));
  cout << s << endl;
  return 0;
}
