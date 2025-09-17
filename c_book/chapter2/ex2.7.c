#include <stdio.h>

#define EXIT_SUCCESS 0

int invert(int x, int p, int n) {
  int mask = (~0 << (p + 1)) | ~(~0 << (p + 1 - n));
  mask = ~mask;
  x = x ^ mask;
  return x;
}

void print_binary(int n) {
  int num_bits = sizeof(int) * 8;
  for (int i = num_bits - 1; i >= 0; i--) {
    int bit = (n >> i) & 1;
    printf("%d", bit);
  }
  printf("\n");
}
int main(int argc, char *argv[])
{
  int test_num = 0b00100010;
  print_binary(invert(test_num, 4, 2));
  return EXIT_SUCCESS;
}
