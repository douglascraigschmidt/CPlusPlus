#include <memory.h>
#include <cstdlib>
#include "stack.h"

int stack_create (stack *s, size_t size) {
  s->top_ = 0;
  s->size_ = size;
  s->stack_ = (T *) malloc (size * sizeof (T));
  return s->stack_ == 0 ? -1 : 0;
}

void stack_destroy (stack *s) {
  free ((void *) s->stack_);
}

void stack_push (stack *s, T item) {
  s->stack_[s->top_++] = item; 
}

void stack_pop (stack *s) {
   s->top_--;
}

void stack_top (stack *s, T *item) {
  *item = s->stack_[s->top_ - 1]; 
}

int stack_empty (stack *s) {
  return s->top_ == 0; 
}

int stack_full (stack *s) {
  return s->top_ == s->size_;
}
