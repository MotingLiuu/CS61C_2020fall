#include <stdio.h>

int main(int argc, char *argv[])
{
  int c, nb = 0;

  while((c = getchar()) != EOF){
    if(c == '\n' || c == '\t' || c == ' '){
      nb++;
      printf("nb is %d\n", nb);
    }
  }
  return 0;
}
