#include "calc.h"
#include <ctype.h>
#include <stdio.h>
int getch(void);
void ungetch(int);

int getop(char s[]) {
int i, c;
while ((s[0] = c = getch()) == ' ' || c == '\t')
;
s[1] = '\0';
if (!isdigit(c) && c != '.' && c != '-')
if (!isalpha(c))
return c; // not a number
i = 0;
if (isalpha(c)) {
while(isalpha(s[++i] = c = getch()))
;
s[i] = '\0';
if (c != EOF)
ungetch(c);
return FUNC;
}
if (c == '-') {
if (!isdigit(c = getch()) && c != '.') {
if (c != EOF)
ungetch(c);
return '-';
} else {
s[++i] = c; // negative number
}
}
if (isdigit(c))
while (isdigit(s[++i] = c = getch()))
;
if (c == '.')
while (isdigit(s[++i] = c = getch()))
;
s[i] = '\0';
if (c != EOF)
ungetch(c);
return NUMBER;
}
