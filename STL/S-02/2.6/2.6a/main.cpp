#include <iostream>  
using namespace std;

/**
 * Three types of parameters can be used with templates:
 *
 * . Typed template parameters  
 * . Non-type template parameters  
 * . Template template parameters 
 *
 * Templates can have regular typed parameters, similar to those found
 * in functions. Typed template parameters are preceded by the keyword
 * typename or class.
 * 
 * Templates can also have regular parameters - these are called "non
 * type" template parameters.
 * 
 * The syntax of a non-typed template parameter is the same as a
 * declaration of one of the following types:
 *
 * . integral or enumeration  
 * . pointer to object or pointer to function 
 * . reference to object or reference to function 
 * . pointer to member.  
 * 
 * A program may qualify a non-type template parameter with const or
 * volatile.
 *
 * Non-type template parameters have restrictions: they must be
 * integral values, enumerations, or instance pointers with external
 * linkage. They can't be string literals nor global pointers since
 * both have internal linkage. Nor can they be floating point,
 * typename or void type.
 *
 * Non-type template parameters are not lvalues, i.e., they are
 * simply "plain old literal data"/
 */

/**
 * In Class below, int N is a non-typed template parameter.
 */
template <typename T, int N>  // typed param T, non-type param N
class Class { 
public:
    void setmem (int x, T value);
    T getmem (int x); 
private:
   T memblock[N] = {0};
};

template<typename T, int N>
void Class<T, N>::setmem(int x, T value) {
  memblock[x] = value;
}

template<typename T, int N>
T Class<T, N>::getmem(int x) {
    return memblock[x];
}

/**
 * A function can also define non-type function template parameters.
 */
template <typename T, int V>
T add (const T & n) {
    return n + V;
}

int main () { 
   Class <int,5> myints;
   Class <double,15> myfloats; 
   myints.setmem (0,100); 
   myfloats.setmem (3,3.1416); 
   cout << myints.getmem(0) << endl; 
   cout << myfloats.getmem(3) << endl;

   int i;
   i = add<int,6> (10);
   cout << "i = " << i << endl;
   return 0; 
} 
