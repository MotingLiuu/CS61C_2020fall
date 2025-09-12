#include <stdio.h>

int main(int argc, char *argv[])
{
  printf("The result of getchar() != EOF is %2d\n", getchar() != EOF);
  return 0;
}
