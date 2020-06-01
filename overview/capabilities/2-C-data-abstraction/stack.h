/* Type of Stack element. */
typedef int T;
typedef struct { size_t top_, size_; T *stack_; } Stack;

/* Stack interface. */
int stack_create (Stack *s, size_t size);
void stack_destroy (Stack *s);
void stack_push (Stack *s, T item);
void stack_top (Stack *s, T *item);
void stack_pop (Stack *s);

/* Must call before pop'ing */
int stack_empty (Stack *);

/* Must call before push'ing */
int stack_full (Stack *);
