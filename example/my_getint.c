#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#define BUFSIZE 100

int buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;      // next free position in buf

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (c == EOF) {
    return;
  }
  if (bufp >= BUFSIZE) {
    printf("ungetch: too many characters\n");
  } else {
    buf[bufp++] = c;
  }
}


int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') 
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
         *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(int argc, char *argv[]) {
    int array[26];
    for (int i = 0; i < 26 && getint(&array[i]) != EOF; i++)
        printf("%d is saved to array", array[i]);
        ;
}