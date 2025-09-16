#include <stdio.h>

#define MAXLEN 1000
#define EXIT_SUCCESS 0

void  reverse(char reversed_str[], char str1[]) {
  int len = 0;

  while (str1[len] != '\0') {
    len++;
  }
  for (int i = 0; i < len; i++) {
    reversed_str[i] = str1[len - i - 1];
  }
  reversed_str[len] = '\0';
}

int main(int argc, char *argv[])
{
  char test_string[] = "This is a test setence.";
  char revered_str[MAXLEN];
  reverse(revered_str, test_string);
  printf("%s\n", revered_str);
  return EXIT_SUCCESS;
}
