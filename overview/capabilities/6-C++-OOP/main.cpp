#include <iostream>

#include "l_stack.h"
#include "v_stack.h"

using namespace std;

template <typename T>
static stack<T> *
make_stack (bool use_vstack, size_t size) {
  if (use_vstack)
    return new v_stack<T>(size);
  else
    return new l_stack<T>(size);
}

template <typename T>
static void print_top (stack<T> *sp) {
  std::cout << "top = " 
            << sp->top () // (*sp->vptr[3])(sp);
            << std::endl;
}

static const size_t MAX_SIZE = 10;

int main(int argc, char *argv[]) {
  std::unique_ptr <stack<int>> sp (make_stack<int> (argc > 1,
                                                      MAX_SIZE));

  int item = 0;

  try {
    for (;;)
      sp->push(item++);
  } catch (stack<int>::overflow &ex) {
    cout << ex.what() << endl;
  }

  try {
    for (;;) {
      std::cout << "top item = " << sp->top() << std::endl;
      sp->pop();
    }
  } catch (stack<int>::underflow &ex) {
    cout << ex.what() << endl;
  }

  // Termination is handled automatically.

  return 0;
}
