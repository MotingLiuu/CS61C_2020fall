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
    if (isupper(c)) {
        return VAR;
    } 
    i = 0;
    if (islower(c)) {
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
    } else if (!isdigit(c) && !(c == '.')) {
        return c;
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
