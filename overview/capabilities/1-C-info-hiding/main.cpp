#include <stdio.h>

#include "stack.h"

// Max size of the stack.
int MAX_STACK = 10;

/**
 * This implementation of the stack example uses "information hiding".
 * https://en.wikipedia.org/wiki/Information_hiding.
 */
int main() {
  T item = 0;

  create(MAX_STACK);
  /* Oops, forgot to call create()! */

  while (!full())
    push(item++);

  while (!empty()) {
    T i;
    top (&i);
    printf("top item = %d\n", i);
    pop ();
  }

  destroy ();
  /* Oops, forgot to call destroy()! */
}
