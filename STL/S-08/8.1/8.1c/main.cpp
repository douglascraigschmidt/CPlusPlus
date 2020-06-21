#include <iostream>

using namespace std;

float Plus (float a, float b) { return a + b; }
float Minus (float a, float b) { return a - b; }

/**
 * A function pointer can be provided as a function's calling
 * argument; this is how it works when using a callback function. The
 * following code shows how to pass a pointer to a function, pt2Func,
 * which returns an int and takes a float and two chars.
 */
void 
pass_ptf(float (*pt2Func)(float, char, char))  {
  // Call using function pointer.
  float result = (*pt2Func)(12, 'a', 'b');     

  cout << result << endl;
}

/**
 * A function that can be passed to pass_ptf().
 */
static float
aFun(float f, char a, char b) {
    return f + a + b;
}

/**
 * A function pointer can be a function's return value. The following
 * code shows two ways to return a pointer to a function that takes
 * two floats as arguments and returns a float. To return a pointer to
 * a member function,  just change the definitions/declarations of the
 * function pointers. 
 *
 * Here is one solution where a function takes a char and returns a
 * pointer to a function that takes two floats and returns a float.
 * The variable opCode specifies which function to return, and the
 * functions pointed to are the Plus and Minus defined in the examples
 * above.
 */
typedef float(*pt2Func)(float, float);

static pt2Func 
get_ptf (char opCode) {
  if (opCode == '+')
    return &Plus;
  else if (opCode == '-')
    return &Minus;
  else
    return nullptr;
}

/**
 * This program demonstrates how to use the pointers to functions
 * defined above.
 */
int main() {
  // Pass a function as a parameter.
  pass_ptf(&aFun);

  // Define a function pointer and initialize it to NULL.
  float (*pt2Function)(float, float) = nullptr;

  // Get the function pointer from function get_ptf().
  pt2Function = get_ptf('+');
  cout << (*pt2Function)(2.4, 4.2) << endl; // call function using the pointer

  // Get function pointer from function get_ptf().
  pt2Function = get_ptf('-');
  cout << (*pt2Function)(4.2, 2.4) << endl; // call function using the pointer
}
