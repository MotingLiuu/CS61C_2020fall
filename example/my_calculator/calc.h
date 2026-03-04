#include <stdbool.h>
#define NUMBER '0'
#define FUNC 'f'
#define VAR 'v'
void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
void print_top(void);
void duplicate_top(void);
void swap_top(void);
void clear_stack(void);
int func_to_int(char []);
bool stack_is_empty(void);
bool top_is_var(void);
void push_var(char c);
char pop_var();
void write_value2var(char c, double value);