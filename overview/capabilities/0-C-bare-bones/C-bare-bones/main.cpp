#include <stdio.h>

// Type of elements in the stack.
typedef int T;

// Max size of the stack.
#define MAX_STACK 10

int main() {
  T stack[MAX_STACK];

  T item = 1;

  for (int top = 0; top < MAX_STACK; ++top)
    stack[top] = item * top; // push

  while (--top >= 0)
    printf("top item = %d", stack[top]); // pop

  return 0;
}
