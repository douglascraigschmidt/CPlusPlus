#include <iostream>

#include "l_stack.h"
#include "v_stack.h"

using namespace std;

/**
 * This factory method creates the designated stack.
 */
template <typename T>
static unique_ptr<stack<T>>
make_stack (bool use_vstack, size_t size) {
  if (use_vstack)
    return make_unique<v_stack<T>>(size);
  else
    return make_unique<l_stack<T>>(size);
}

/**
 * This method prints the top item of the stack, without having
 * any dependency on the actual subclass accessed via {@code sp}.
 */
template <typename T>
static void print_top (stack<T> *sp) {
  std::cout << "top item = "
            << sp->top () // (*sp->vptr[n])(sp);
            << std::endl;
}

/**
 * Max size of our stack.
 */
static const size_t MAX_SIZE = 10;

/**
 * This example shows how using our stack abstract base class make
 * it possible to write code that does not depend on the stack
 * implementation.
 */
int
main(int argc, char *argv[]) {
  std::unique_ptr <stack<int>> sp (make_stack<int> (argc > 1,
                                                    MAX_SIZE));
  auto item = 0;

  try {
    for (;;)
      sp->push(item++);
  } catch (stack<int>::overflow &ex) {
    cout << ex.what() << endl;
  }

  try {
    for (;;) {
      print_top(sp.get());
      sp->pop();
    }
  } catch (stack<int>::underflow &ex) {
    cout << ex.what() << endl;
  }

  // RTTI.
  if (dynamic_cast<v_stack<int> *>(sp.get()))
    cout << "configured with v_stack" << endl;
  else if (dynamic_cast<l_stack<int> *>(sp.get()))
    cout << "configured with l_stack" << endl;

  // Termination is handled automatically.

  return 0;
}
