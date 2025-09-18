#include <stdio.h>

#define EXIT_SUCCESS 0

int binsearch(int x, int v[], int n) {
  int low, mid, high;
  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low + high) / 2;
    if (v[mid] >= x) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  if (v[mid] == x) {
    return mid;
  } else {
    return -1;
  }
}

int main(int argc, char *argv[])
{
  int test_num[] = {1, 2, 3, 4, 4, 6, 7, 8, 9};
  printf("%d\n", binsearch(4, test_num, 9));
  printf("%d\n", binsearch(5, test_num, 9));
  return EXIT_SUCCESS;
}
