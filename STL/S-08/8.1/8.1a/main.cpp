#include <iostream>

using namespace std;

/**
 * Functors work very much like function pointers, so we'll start by
 * reviewing how C++/C function pointers work. Function pointers are
 * pointers, i.e., variables, that point to the address of a function.
 * A running program gets only a certain amount of space in the main
 * memory. Both the executable compiled program code and the used
 * variables reside in this memory. A function in the program code
 * becomes nothing more than an address in memory.
 *
 * When calling a function, say f(), at a certain point called label
 * in a program, just put the call to the function f() at the point
 * label in the source code. Then compile the program and every time
 * the program execution reaches that point in the code, the function
 * is called.
 *
 * But what is efficient, if it is not known at compile time which
 * function should be called? Perhaps different objects will be
 * created in the program and this determines the proper function
 * call?
 * 
 * Determining the function to call at runtime might be done using
 * callback functions or selecting a functions out of a pool of
 * possible functions using a switch statement.
 *
 * Another way to achieve this functionality is to use the powerful
 * concept of a function pointer.
 *
 * Here is an example first using a switch statement and then doing
 * the same thing with a function pointer.  This is a function
 * designed to perform the four basic arithmetic operations as
 * function calls.
 */
float Plus (float a, float b) { return a+b; }
float Minus (float a, float b) { return a-b; }
float Multiply(float a, float b) { return a*b; }
float Divide (float a, float b) { return a/b; }

/**
 * The char variable opCode specifies which operation to execute.
 */
void Switch(float a, float b, char opCode)  {
    float result;
    switch(opCode)   {
    case '+' :
      result = Plus (a, b); 
      break;
    case '-' :
      result = Minus (a, b); 
      break;
    case '*' :
      result = Multiply (a, b); 
      break;
    case '/' :
      result = Divide (a, b); 
      break; 
    }
    cout << "Switch: 2 + 5 = ";
    cout << result << endl;
}

/**
 * Here is the same problem but using a function pointer named
 * pt2Func, which points to a function which takes two floats and
 * returns a float. The function pointer "specifies" which arithmetic
 * operation is executed.
 */
void SwitchFunctPtr(float a, float b, float (*pt2Func)(float, float))  {
  float result = pt2Func(a, b); // call using function pointer
  cout << "Switch replaced by function pointer: 2 - 5 = ";
  cout << result << endl;
}

/**
 * This program demonstrates how to call the two functions defined above.
 */
int main() {
  Switch(2.0,
          5.0, /* '+' specifies function 'Plus' will be executed */
          '+');

  SwitchFunctPtr (2.0, 5.0, /* pointer to function 'Minus' */ &Minus);

}
