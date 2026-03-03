#define NUMBER '0'
#define FUNC 'f'
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