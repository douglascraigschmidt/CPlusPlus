#include <memory.h>
#include <cstdlib>
#include "stack.h"
/* Hidden within this file. */
static int top_, size_; 
static T *stack_;

int create (int size) {
  top_ = 0; size_ = size;
  stack_ = (T *) malloc (size * sizeof (T));
  return stack_ == 0 ? -1 : 0;
}

void destroy () {
  free ((void *) stack_); 
}

void push (T item) { 
  stack_[top_++] = item;
}

void pop () {
  --top_; 
}

void top (T *item) {
  *item = stack_[top_ - 1]; 
}

int empty () {
  return top_ == 0; 
}

int full () { 
  return top_ == size_; 
}
