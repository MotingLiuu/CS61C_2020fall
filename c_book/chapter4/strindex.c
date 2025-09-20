#include <stdio.h>
#include <stdlib.h>

int strindex(char source[], char target[]) {
  int i, j;
  int last_pos = -1;
  for (i = 0; source[i] != '\0'; i++) {
    for (j = i; source[j] == target[j - i] && source[j] != '\0' &&
                target[j - i] != '\0';
         j++) {
      ;
    }
    if (target[j - i] == '\0') {
      last_pos = i;
    }
  }
  return last_pos;
}

int main(int argc, char *argv[]) {
  char source_str[] = "This is the test str, This is the test str.";
  char target_str[] = "is";
  printf("The last position is: %d", strindex(source_str, target_str));
  return EXIT_SUCCESS;
}
