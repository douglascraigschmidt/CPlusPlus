/* Type of stack element. */
typedef int T;

/* Define the stack data structure. */
typedef struct { size_t top_, size_; T *stack_; } stack;

/* stack interface. */
int stack_create (stack *s, size_t size);
void stack_destroy (stack *s);
void stack_push (stack *s, T item);
void stack_top (stack *s, T *item);
void stack_pop (stack *s);

/* Must call before pop'ing */
int stack_empty (stack *);

/* Must call before push'ing */
int stack_full (stack *);
