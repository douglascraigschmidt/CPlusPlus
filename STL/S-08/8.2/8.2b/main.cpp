#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/**
 * From binary_function and unary_function base classes, also found in <functional>
 * are the following functor classes. These are used in the STL for working as
 * parameters to both containers and algorithms.
 * 
 * // Arithmetic functors
 * template <typename T> struct plus;       		// binary +
 * template <typename T> struct minus;      		// binary -
 * template <typename T> struct multiplies; 		// binary *
 * template <typename T> struct divides;    		// binary /
 * template <typename T> struct modulus;    		// binary %
 * template <typename T> struct negate;     		// unary -
 * 
 * // Comparisons
 * template <typename T> struct equal_to;      		// ==
 * template <typename T> struct not_equal_to;  		// !=
 * template <typename T> struct less;          		// <
 * template <typename T> struct greater;       		// >
 * template <typename T> struct less_equal;    		// <=
 * template <typename T> struct greater_equal; 		// >=
 * 
 * // Logical operations
 * template <typename T> struct logical_and; 		// binary &&
 * template <typename T> struct logical_or;  		// binary ||
 * template <typename T> struct logical_not; 		// unary !
 * 
 * The following are some examples of functor base classes (plus their
 * derived classes) found in <functional> for functors that take one
 * or two arguments. Custom functor classes can inherit from these
 * classes or be defined on their own. Here are a few templates of the
 * binary functors.
 *
 * template <typename _Arg1, typename _Arg2, typename _Result>
 * struct binary_function {
 *   typedef _Arg1 first_argument_type;
 *   typedef _Arg2 second_argument_type;
 *   typedef _Result result_type;
 * };    
 *     
 * template <typename T>
 * struct plus : public binary_function<T,T,T> {
 *   T operator()(const T& x, const T& y) const { return x + y; }
 * };
 * 
 * template <typename T>
 * struct minus : public binary_function<T,T,T> {
 *   T operator()(const T& x, const T& y) const { return x - y; }
 * };
 * 
 * template <typename T>
 * struct multiplies : public binary_function<T,T,T> {
 *   T operator()(const T&  x, const T&  y) const { return  x * y; }
 * };
 * 
 * template <typename T>
 * struct divides : public binary_function<T,T,T> {
 *   T operator()(const T&  x, const T&  y) const { return  x / y; }
 * };
 */

/**
 * Here is the unary functor base class and its derived class.
 *
 * template <typename _Arg, typename _Result>
 * struct unary_function {
 *   typedef _Arg argument_type;
 *   typedef _Result result_type;
 * };
 * 
 * template <typename T>
 * struct negate : public unary_function< T, T > 
 * {
 *   T operator()(const T & x) const { return -x; }
 * };
 */

/**
 * Here is an example of a user-defined functor that extends the
 * unary_function template.
 */
class is_even : public unary_function<int, bool> {
public:
  bool operator()(int i) {
    return (result_type) !(i % 2);
  }
};

/**
 * The example below shows how we can call this function just like any
 * other function, only being a class it can hold data as well as
 * several functions within itself (not shown in this example).
 */
int main() {
  vector<int> aVect;

  for(int i = 1; i <= 20; i++)
     aVect.push_back(i);

  cout << "Sequence: ";
  for(auto i : aVect)
    cout << i << " ";
  cout << endl;

  auto c = count_if(aVect.begin(), aVect.end(), is_even());
  cout << c << " numbers are evenly divisible by 2.";

  return 0;
}
