#include <stdio.h>

int main(int argc, char *argv[]) {
  printf("Hello, World!\n");
  printf("count of arguments: %d\n", argc);
  for (int i = 0; i < argc; i++) {
    printf("argument %d: %s\n", i, argv[i]);
  }
  return 0;
}
