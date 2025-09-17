#include <stdio.h>

#define EXIT_SUCCESS 0

int rightrot(int x, int n) {
  int x_l, x_r;
  x_r = x >> n;
  x_l = (x << ((sizeof(x) * 8) - n));
  return x_r | x_l;
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
  int test_num = 0b0010001101;
  print_binary(rightrot(test_num, 4));
  return EXIT_SUCCESS;
}
