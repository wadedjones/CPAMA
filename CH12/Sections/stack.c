/* push and pop functions of a stack with pointers */
int n = 10;
int contents[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int *top_ptr = &contents[0];

void stack_overflow(void) { return; }  // not a valid function
void stack_underflow(void) { return; } // not a valid function

int is_full(void) { return 0; }  // not a valid function
int is_empty(void) { return 0; } // not a valid function

void push(int i) {
  if (is_full()) {
    stack_overflow();
  } else {
    *top_ptr++ = i;
  }
}

int pop(void) {
  if (is_empty()) {
    stack_underflow();
  } else {
    return *--top_ptr;
  }
  return 1;
}
