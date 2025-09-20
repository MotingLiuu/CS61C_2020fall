#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10000

char pattern[] = "ould";

int my_getline(char s[], int lim) {
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
int strindex(char source[], char target[]) {
  int i, j, k;

  for (int i = 0; source[i] != '\0'; i++) {
    for (j = i, k = 0; target[k] != '\0' && source[j] == target[k]; j++, k++) {
      ;
    }
    if (k > 0 && target[k] == '\0') {
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  int found = 0;
  while (my_getline(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  printf("Count: %d", found);
  return found;
}
