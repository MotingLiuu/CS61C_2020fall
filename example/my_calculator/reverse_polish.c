#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_OP 100
double variables[26];
int last_var = 0;

int main() {
  int type;
  double op2;
  double result;
  char s[MAX_OP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case FUNC:
      switch (func_to_int(s)) {
        case 1:
          push(result = sin(pop()));
          write_value2var('Z', result);
          break;
        case 2:
          push(result = cos(pop()));
          write_value2var('Z', result);
          break;
        case 3:
          op2 = pop();
          push(result = pow(pop(), op2));
          write_value2var('Z', result);
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
        default:
          printf("Unknown func or command %s\n", s);
          break;
      }
      break;
    case VAR:
      push_var(s[0]);
      break;
    case '+':
      push(result = pop() + pop());
      write_value2var('Z', result);
      break;
    case '*':
      push(pop() * pop());
      write_value2var('Z', result);
      break;
    case '-':
      op2 = pop();
      push(result = pop() - op2);
      write_value2var('Z', result);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0) {
        push(result = pop() / op2);
        write_value2var('Z', result);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0) {
        push(result = (int)pop() % (int)op2);
        write_value2var('Z', result);
      } else {
        printf("error: zero divisor\n");
      }
      break;
    case '=':
      if (top_is_var()) {
          write_value2var(pop_var(), pop());
      } else {
          op2 = pop();
          if (top_is_var()) {
            write_value2var(pop_var(), op2);
          } else {
            printf("There should be at least 1 var\n");
          }
      }
      break;
    case '\n':
      break;
    default:
      printf("error: unknow command %s, type %c", s, (char)type);
      break;
    }
    
  }
}
