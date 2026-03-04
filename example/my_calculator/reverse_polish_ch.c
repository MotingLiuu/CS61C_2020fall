#define BUFSIZE 100
#include <stdio.h>
#include <stdbool.h>

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

void ungets(char *s) {
  for(int i = 0; s[i] != '\0'; i++) {
    ungetch(s[i]);
  }
}