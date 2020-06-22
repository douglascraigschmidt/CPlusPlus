#include <iostream>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

/**
 * Sometimes is it convenient to compare two values and the STL
 * relational functors have the standard six math functions =, != , >,
 * >=, * <, and <=.
 * 
 * Predicate             Type    Result
 * equal_to<type>()      Binary  Equality of parameters (param1 == param2)
 * 
 * not_equal_to<type>()  Binary  Inequality of parameters (param1 !=
 *                               param2) 
 * 
 * less<type>()          Binary  Parameter 1 less than parameter 2
 *                               (param1 < param2) 
 * 
 * greater<type>()       Binary  Parameter 1 greater than parameter 2
 *                               (param1 > param2) 
 *  
 * less_equal<type>()    Binary  Parameter 1 less than or equal to
 *                               parameter 2 (param1 <= param2) 
 * 
 * greater_equal<type>() Binary  Parameter 1 greater than or equal to
 *                               parameter 2 (param1 >= param2) 
 *  
 * The STL templates also enable the creation of custom binary or
 * unary functors that would work similarly to their in the
 * algorithms:
 *  
 * template <typename Arg, typename Result>
 * struct unary_function {
 *    typedef Arg argument_type;
 *    typedef Result result_type;
 * };
 * 
 * template <typename Arg1, typename Arg2, typename Result>
 * struct binary_function {
 *    typedef Arg1 first_argument_type;
 *    typedef Arg2 second_argument_type;
 *    typedef Result result_type;
 * };
 */

/** 
 * Forward declarations.
 */ 
static void demonstrate_on_string();
static void demonstrate_on_array();

/** 
 * Here is an example to remove spaces in a string that uses the
 * equal_to<> and bind<> functors. It says perform remove_if() when
 * the equal to function finds a blank char in the string.
 */
int main() {
  demonstrate_on_string();
  demonstrate_on_array();

  return 0;
}

static void
demonstrate_on_string() {
  string s = "spaces in text";
  cout << s << endl;
  auto new_end = remove_if(begin(s),
                           end(s),
                           bind(equal_to<>(), placeholders::_1, ' '));

  cout << s << endl; // Note the "xt" characters aren't removed at the end!

  // Now let's remove the characters at the end.
  s.erase(new_end, s.end());

  cout << s << endl;
}

static void
demonstrate_on_array() {
  char s[] = "spaces in text";
  cout << s << endl;

  auto new_end = remove_if(begin(s),
                           end(s),
                           bind(equal_to<>(), placeholders::_1, ' '));

  /*
   auto new_end = remove_if(begin(s),
                            end(s),
                       [](char c) { return c == ' ';}); */

  cout << s << endl; // Note the "xt" characters are removed at the end!
}

