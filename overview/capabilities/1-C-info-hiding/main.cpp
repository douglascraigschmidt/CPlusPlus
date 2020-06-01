#include <stdio.h>

#include "stack.h"

// Max size of the stack.
int MAX_STACK = 10;

int main() {
  T item = 0;

  create(MAX_STACK);
  /* create(MAX_STACK); */
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
  /* destroy (); */
  /* Oops, forgot to call destroy()! */
}
