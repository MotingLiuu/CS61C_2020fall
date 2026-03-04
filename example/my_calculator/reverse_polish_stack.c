#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
double variables[26];
char var_stack[MAX_STACK_SIZE];
int stack_top = 0;

bool stack_is_empty(void) {
  if (stack_top == 0) {
    return true;
  } else {
    return false;
  }
}

bool top_is_var(void) {
  if (var_stack[stack_top - 1] != '\0')
    return true;
  return false;
}

void push(double value) {
  if (stack_top < MAX_STACK_SIZE) {
    var_stack[stack_top] = '\0';
    stack[stack_top++] = value;
  } else {
    printf("Stack overflow\n");
  }
}

double pop(void) {
  if (stack_top > 0) {
    if (!top_is_var()) {
      return stack[--stack_top];
    } else {
      return variables[var_stack[--stack_top] - 'A'];
    }
  } else {
    printf("Stack underflow\n");
    return 0.0; // Return a default value
  }
}

char pop_var(void) {
  if (stack_top > 0 && top_is_var()) {
    return var_stack[--stack_top];
  } else if (!top_is_var()) {
    printf("top is not var\n");
  } else {
    printf("Stack underflow\n");
  }
}

void write_value2var(char c, double value) {
  variables[c - 'A'] = value;
}

void push_var(char c) {
  var_stack[stack_top++] = c;
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
