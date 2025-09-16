#include <stdio.h>

int power(int m, int n);

int main(int argc, char *argv[])
{
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      printf("power(%d, %d) is %d\n", i, j, power(i, j));
    }
  }
  return 0;
}

int power(int m, int n) {
  int result = 1;
  
  for (int i = 0; i < n; i++) {
    result = result * m;
  }
  return result;
}
