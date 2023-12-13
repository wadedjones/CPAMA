#include <stdbool.h>

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(int i, int *calc_stack);
int pop(int *calc_stack);
