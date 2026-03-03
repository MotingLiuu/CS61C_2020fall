#include <stdio.h>
#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
int stack_top = 0;

void push(double value) {
  if (stack_top < MAX_STACK_SIZE) {
    stack[stack_top++] = value;
  } else {
    printf("Stack overflow\n");
  }
}

double pop(void) {
  if (stack_top > 0) {
    return stack[--stack_top];
  } else {
    printf("Stack underflow\n");
    return 0.0; // Return a default value
  }
}

void print_top(void) { printf("top: %f\n", stack[stack_top - 1]); }

void duplicate_top(void) {
  if (stack_top < MAX_STACK_SIZE) {
    double top_value = pop();
    push(top_value);
    push(top_value);
  } else {
    printf("Stack overflow\n");
  }
}

void swap_top(void) {
  if (stack_top >= 2) {
    double top1 = pop();
    double top2 = pop();
    push(top1);
    push(top2);
  } else {
    printf("Not enough elements to swap\n");
  }
}

void clear_stack(void) { stack_top = 0; }
