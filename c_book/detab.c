#include <stdio.h>

#define EXIT_SUCCESS 0
#define column_num 8

int main(int argc, char *argv[])
{
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (int i = 0; i < 4; i++) {
        putchar(' ');
      }
    } else {
      putchar(c);
    }
  } 

  return EXIT_SUCCESS;
}
