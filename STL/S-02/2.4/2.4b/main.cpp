#include <iostream>

/**
 * Class templates can be partly specialized, as shown by this
 * template class that takes two type parameters.
 */
template <typename T, typename U>
struct Class
{
  Class () { std::cout << "Class <T, U>\n"; }
};
	
/**
 * The following are partial specializations of the template Class.
 */
template <typename T>   	//specialize so that both are same datatype
struct Class <T, T> {
  Class () { std::cout << "Class<T, T>\n"; }
};

template <typename T>   	//specialize so that second datatype is int
struct Class <T, int > {
  Class () { std::cout << "Class<T, int>\n"; }
};

template <typename T, typename U>   // both are now pointers
struct Class <T *, U *> {
  Class () { std::cout << "Class<T*, U*>\n"; }
};

int main(void) {
  Class <int, double> a;     // prints "Class<T, U>"
  Class <double, double> b;  // prints "Class<T, T>"
  Class <double, int> c;     // prints "Class<T, int>"
  Class <int *, double *> d; // prints "Class<T*, U*>"

  // Class <int, int> e;        // prints??

  // Can fix ambiguity with 
  // template <>
  // struct Class <int, int> {
  //   Class () { std::cout << "Class<int, int>\n"; }
  // };

  return 0;
}
