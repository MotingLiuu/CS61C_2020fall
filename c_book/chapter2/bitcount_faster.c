#include <stdio.h>

#define EXIT_SUCCESS 0

int bitcount_faster(unsigned x) {
  int count = 0;
  for (; x; x &= (x - 1)) {
    count++;
  }
  return count;
}

int main(int argc, char *argv[])
{
  int test_int = 0b101101010;
  printf("%d\n", bitcount_faster(test_int));
  return EXIT_SUCCESS;
}
