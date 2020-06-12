/* Type of Stack element. */
typedef int T;

/* Stack interface. */
int create(int size);
void destroy();
void push(T new_item);
void pop();
void top(T *cur_top);
int empty();
int full();
