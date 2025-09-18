#include <stdio.h>

#define EXIT_SUCCESS 0

int binsearch(int x, int v[], int n);

int main(int argc, char *argv[])
{
  int test_array[] = {1, 2, 3, 4, 5, 6, 7, 11, 15, 25, 26, 28, 30, 31};
  printf("%d\n", binsearch(24, test_array, 7));
  return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n) {
  int low, mid, high;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (v[mid] < x) {
      low = mid + 1;
    } else if (v[mid] > x) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}
          
