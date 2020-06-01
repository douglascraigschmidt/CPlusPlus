#include <stdio.h>

#include "stack.h"

// Max size of the stack.
int MAX_STACK = 10;

int main() {
  /* Multiple stacks! */
  Stack s1, s2, s3;

  T item = 0;

  stack_create(&s1, MAX_STACK);

  /* stack_create(&s1, MAX_STACK); */
  /* Oops, forgot to call stack_create()! */

  while (!stack_full(&s1))
    stack_push(&s1, item++);

  while (!stack_empty(&s1)) {
    T i;
    stack_top (&s1, &i);
    printf("top item = %d\n", i);
    stack_pop (&s1);
  }

  // s2 = s3; /* Disaster due to aliasing!!! */

  // Destroy some uninitialized stacks!
  stack_destroy (&s1);
  /* stack_destroy (&s2);
  stack_destroy (&s3); */
}
