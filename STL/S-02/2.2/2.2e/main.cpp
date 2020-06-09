#include "min.h"
#include <iostream>

/**
 * Summary of function templates
 *
 * . C++ function templates define a family of functions for different
 *   datatypes.
 * 
 * . When a program invokes a function template the arguments passed
 *   to the function direct C++ to instantiate only the function for
 *   those datatypes from the template.
 * 
 * . A program can invoke a function template either by explicitly
 *   telling C++ the data types to use, or it can simply pass arguments
 *   to the function, leaving it up to C++ to deduce the right
 *   data types.
 * 
 * . Function templates can be overloaded, but this is best done
 *   carefully.
 * 
 * . When using function templates, be sure that the type of arguments
 *   used to invoke the function will work with the given set of
 *   function templates.
 * 
 * . Know that if an ordinary function has the same name as a function
 *   template, any call that fits this ordinary function, will use the
 *   ordinary function instead of the template, even if a template
 *   would also fit.
 */
int main() {
  auto i = min(9, 6);
  std::cout << "Minimum of integers: " <<  i << std::endl;
                                         
  auto d = min(10.5, 11.3);
  std::cout <<"Minimum of Doubles: " << d << std::endl;
    
  // Compile error since implicit cast not acceptable for templates.
  // d = min(10, 11.3);

  // Function template will accept an explicit cast though.
  d = min<double>(10, 11.3);                        
  std::cout << "Minimum of Double: " << d << std::endl;

  // Can use type deduction to define the type.
  auto e = min_ex(10, 11.3);
  std::cout << "Minimum of " << typeid(e).name() << ": " << e << std::endl;

  // 3 arguments work to call the overloaded function template.
  i = min(3, 6, 4);			
  std::cout << "Minimum int 3 Parameters: " << i  << std::endl;
}
