#include <stdio.h>

#define EXIT_SUCCESS 0

char lower(char ch) {
  return 'A' < ch && ch < 'Z' ? ch - ('A' - 'a') : ch; 
}

int main(int argc, char *argv[])
{
  char test_ch = 'B';
  printf("%c\n", lower(test_ch));
  return EXIT_SUCCESS;
}
