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
