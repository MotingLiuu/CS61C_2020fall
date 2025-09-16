#include <stdio.h>

int main(int argc, char *argv[])
{
  int c, histogram[256];
  for (int i = 0; i < 256; i++) {
    histogram[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    histogram[c]++;
  }
  for(int i = 0; i < 256; i++) {
    if (histogram[i] != 0) {
      printf("%c:%d\n", i, histogram[i]);
    }
  }
  return 0;
}
