#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_OP 100

int main() {
  int type;
  double op2;
  char s[MAX_OP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case FUNC:
      switch (func_to_int(s)) {
        case 1:
          push(sin(pop()));
          break;
        case 2:
          push(cos(pop()));
          break;
        case 3:
          op2 = pop();
          push(pow(pop(), op2));
          break;
        case 4:
          print_top();
          break;
        case 7:
          duplicate_top();
          break;
        case 5:
          swap_top();
          break;
        case 6:
          clear_stack();
          break; 
      }
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(pop() / op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0) {
        push((int)pop() % (int)op2);
      } else {
        printf("error: zero divisor\n");
      }
      break;

    case '\n':
      break;
    default:
      printf("error: unknow command %s\n", s);
      break;
    }
  }
}
