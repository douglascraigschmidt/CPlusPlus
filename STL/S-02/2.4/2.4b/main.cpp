#include <iostream>

/**
 * example_class templates can be partially specialized, as shown by
 * this template example_class that takes two type parameters.
 */
template <typename T, typename U>
struct example_class {
  example_class () { std::cout << "example_class <T, U>\n"; }
};
	
/**
 * The following are partial specializations of the template
 * example_class.
 */
template <typename T>   	//specialize so that both are same datatype
struct example_class <T, T> {
  example_class () { std::cout << "example_class<T, T>\n"; }
};

template <typename T>   	//specialize so that second datatype is int
struct example_class <T, int> {
  example_class () { std::cout << "example_class<T, int>\n"; }
};

template <typename T, typename U>   // both are now pointers
struct example_class <T *, U *> {
  example_class () { std::cout << "example_class<T*, U*>\n"; }
};

/*
template <>
struct example_class <int, int> {
  example_class () { std::cout << "example_class<int, int>\n"; }
}; */

int main() {
  example_class<int, double> a;     // prints "example_class<T, U>"
  example_class<double, double> b;  // prints "example_class<T, T>"
  example_class<double, int> c;     // prints "example_class<T, int>"
  example_class<int *, double *> d; // prints "example_class<T*, U*>"

  // example_class <int, int> e;        // prints??

  return 0;
}
