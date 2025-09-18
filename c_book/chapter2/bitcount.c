#include <stdio.h>

#define EXIT_SUCCESS 0

int bitcount(unsigned x) {
  int b;
  
  for (b = 0; x != 0; x >>= 1) {
    if (x & 1) {
      b++;
    }
  }
  return b;
}

int main(int argc, char *argv[])
{
  int test_num = 0b01001101011;
  printf("%d\n", bitcount(test_num));
  return EXIT_SUCCESS;
}
