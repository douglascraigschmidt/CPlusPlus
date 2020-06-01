#include <memory.h>
#include <cstdlib>
#include "stack.h"

int stack_create (Stack *s, size_t size) {
  s->top_ = 0;
  s->size_ = size;
  s->stack_ = (T *) malloc (size * sizeof (T));
  return s->stack_ == 0 ? -1 : 0;
}

void stack_destroy (Stack *s) {
  free ((void *) s->stack_);
}

void stack_push (Stack *s, T item) {
  s->stack_[s->top_++] = item; 
}

void stack_pop (Stack *s) {
   s->top_--;
}

void stack_top (Stack *s, T *item) { 
  *item = s->stack_[s->top_ - 1]; 
}

int stack_empty (Stack *s) {
  return s->top_ == 0; 
}

int stack_full (Stack *s) {
  return s->top_ == s->size_;
}
