#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define MAXLINE 1000
double stack[MAXLINE];
int stack_top = 0;

double str2float(char *s) {
    double result = 0;
    int sign = 1;
    int scale = 0;
    
    if (*s == '-' || *s == '+') {
        sign = (s[0] == '-') ? -1 : 1;
        s++;
    }
    while (isdigit(*s)) {
        result = result * 10 + (*s - '0');
        s++;
    }
    if (*s == '.') {
        scale = 1;
        s++;
    }
    while(isdigit(*s)) {
        result = result * 10 + (*s - '0');
        scale = scale * 10;
        s++;
    }

    result = (double)sign * result;

    return (scale == 0) ? result : result / scale;
}

int is_func(char *s) {
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/') {
        if (*(s+1) == '\0')
            return *s;
    }
   return 0; 
}

double pop() {
    stack_top--;
    return stack[stack_top];
}

void push(double d) {
    stack[stack_top] = d;
    stack_top++;
}

int main(int argc, char *argv[]) {
    
    while (--argc > 0) {
        int func_num;
        double op2;
        if (func_num = is_func(*(++argv))) {
            switch (func_num) {
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
                    push(pop() / op2);
                    break;
                default:
                    printf("Unrecgnized func\n");
            }
        } else {
            push(str2float(*argv));
        }
    }
    printf("Result: %f.2", pop());
}