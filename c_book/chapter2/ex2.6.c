#include <stdio.h>

#define EXIT_SUCCESS 0

int setbits(int x,int p,int n,int y) {
  int x_l, x_r;
  int result;

  y = y & ~(~0 << n);
  y = y << (p + 1 - n);
  x_l = x & (~0 << (p + 1));
  x_r = x & ~(~0 << (p + 1 - n));
  result = y | x_l | x_r;

  return result;
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
  int x = 0b1001001, y = 0b0010111;
  int result = setbits(x, 2, 1, y);
  print_binary(result);

  return EXIT_SUCCESS;
}
