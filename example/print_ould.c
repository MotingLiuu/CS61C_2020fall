#include <stdio.h>
#define MAXLINE 1000

int getlines(char line[], int max);
int strindex(char source[], char searchfor[]);
int right_most_strindex(char source[], char searchfor[]);

char patter[] = "ould";

int main() {
  char line[MAXLINE];
  int found = 0;
  int right_most_index = 0;

  while (getlines(line, MAXLINE) > 0) {
    if ((right_most_index = right_most_strindex(line, patter)) >= 0) {
      printf("right_mist_index: %d\n", right_most_index);
      found++;
    }
  }
  return found;
}

int right_most_strindex(char s[], char t[]) {
  int i, k;
  i = k = 0;
  int sta_index;
  for (i = 0; s[i] != '\0'; i++)
    ;
  for (k = i; k > 0; k--) {
    sta_index = strindex(&s[k], t);
    if (sta_index >= 0)
      return sta_index + k;
  }
  return -1;
}

int getlines(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
