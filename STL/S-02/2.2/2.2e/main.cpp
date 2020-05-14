#include "min.h"
#include <iostream>

int main() {
  int  i = min(9,6); 		
  std::cout <<"Minimum of integers: "<<  i << std::endl;
                                         
  double d= min(10.5,11.3); 		 	
  std::cout <<"Minimum of Doubles: "<< d << std::endl;
    
  //  Returns error since implicit cast not acceptable for templates
  d = min(10,11.3); 	
  std::cout  << "Minimum of Double: "<< d << std::endl;

  // function template will accept an explicit cast though
  d= min<double>(10,11.3);                        
  std::cout  << "Minimum of Double: " << d << std::endl;
  // 3 arguments work to call the overloaded function template

  i = min(3,6,4);			
  std::cout <<   "Minimum int 3 Parameters: " << i  << std::endl;
}
