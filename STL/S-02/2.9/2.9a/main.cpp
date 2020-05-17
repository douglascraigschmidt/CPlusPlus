#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

/**
 * When working with ordinary classes and functions, C++ programmers
 * place the class and function declarations into header (*.h)
 * files. Then the function implementation and any global variables
 * are defined in separate source (*.cpp) files that #include the
 * class header file. This approach allows the program to link
 * together the class declarations and definitions. Morever, any other
 * program using the class only #include's the class header files.
 * 
 * For template functions, however this method will not work because
 * when a program statement invokes the template function, C++ must be
 * able to instantiate the function based on the template or blueprint
 * of that function family. However, when the C++ compiler looks for a
 * definition in the header file it cannot find one (it’s in the
 * implementation source file).  Therefore, as the compiler processes
 * the implementation source file it doesn’t know what type of
 * datatype function will be instantiated later in the program file.
 *
 * When the compiler processes the program file, it compiler assumes
 * the template function will be defined elsewhere and leaves a
 * reference for the linker to locate where it resides. When the
 * linker comes along to process all the compiled object files
 * together into an executable file, it discovers the reference to
 * ‘find’ the function definition and it can't put the two files
 * (header and source) together to find it.
 * 
 * One way that programmers have solved this is to place all template
 * functions and their full implementation in the same file or to
 * #include the source file at the end of the header file.  This
 * method can increase the cost of using this template header file due
 * to its increased size and the size of any other header files, such
 * as <iostream>, that are often needed in function implementations.
 *
 * Note that non-inline functions create a new copy of the function
 * each time they are instantiated, rather than being expanded at the
 * site of the call.  Occasionally when creating large libraries of
 * functions, this can lead to two copies of the function in different
 * files, though "smart linkers" can eliminate this duplication.
 * 
 * This discussion applies to member template functions, and member
 * functions and data members of class templates. It's good practice
 * to place declarations and definitions in the same file or #include
 * the source file at the end of the header file.
 */

/** 
 * Template functions and member functions are only instantiated when
 * they are used.  Some older C++ compilers had problems instantiating
 * all the templates properly.  One way to prevent linker and
 * compilation errors is to use "explicit instantiation", which
 * provides each template argument when invoking a template
 * function. For example, consider the following small template
 * function. */
template <typename T>
void printDataType (const T& a)  {  cout << typeid(a).name() << endl; }

/** 
 * The following are examples of using this particular function
 * template in a program plus other templates; all being explicitly
 * instantiated.
 */
template <typename T>
struct aClass
{
  aClass () { }
  T result (T t) { return t; }
  void add (const T &t) {}
};

// explicitly instantiate this function template for types int and double
template void printDataType<int>(const int &);
template void printDataType<double>(const double &);

// explicitly instantiate a template class¡¯ constructor for int data
template aClass<int>::aClass();

// explicitly instantiate an entire template class and all its functions
// later cannot explicitly instantiate particular functions of this class
// because ALL are instantiated by this statement
template struct aClass<double>;

// explicitly instantiate just some member functions 
template aClass<string>::aClass();
template void aClass<string>::add(const string  &);
template string aClass<string>::result(string);

/**
 * This function demonstrates the use of printDataType.
 */
int main() {
  aClass<int> ai;
  aClass<double> ad;
  printDataType(ai);
  printDataType(ad);

  return 0;
}
