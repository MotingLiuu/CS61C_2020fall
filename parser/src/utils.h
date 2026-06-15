#pragma once
#include <stdbool.h>
#define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);

int get_token(void);
int tokentype; // type of last token
char token[MAXTOKEN]; // last token string
char name[MAXTOKEN]; // identifier name
char datatype[MAXTOKEN]; // data type = char, int, etc
char out[1000];

int push(char c);
int pop();
bool empty(void);


char getch(void);
void ungetch(char c);



