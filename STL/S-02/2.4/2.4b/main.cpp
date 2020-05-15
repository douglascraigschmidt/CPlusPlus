#include <iostream>

template <typename T, typename U>
struct aClass
{
  aClass () { std::cout << "aClass <T, U>\n"; }
};
	
template <typename T>   	//specialize so that both are same datatype
struct aClass <T, T> {
  aClass () { std::cout << "aClass<T, T>\n"; }
};

template <typename T>   	//specialize so that second datatype is int
struct aClass <T, int > {
  aClass () { std::cout << "aClass<T, int>\n"; }
};

template <typename T, typename U>   // both are now pointers
struct aClass <T *, U *> {
  aClass () { std::cout << "aClass<T*, U*>\n"; }
};

int main(void) {
  aClass <int, double> a;     // prints ¡°aClass<T, U>¡±
  aClass <double, double> b;  // prints ¡°aClass<T, T>¡±
  aClass <double, int> c;     // prints ¡°aClass<T, int>¡±
  aClass <int *, double *> d; // prints ¡°aClass<T*, U*>¡±

  // aClass <int, int> e;        // prints??

  // Can fix ambiguity with 
  // template <>
  // struct aClass <int, int> {
  //   aClass () { std::cout << "aClass<int, int>\n"; }
  // };

  return 0;
}
