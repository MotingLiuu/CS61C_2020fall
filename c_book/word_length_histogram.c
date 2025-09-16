#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[])
{
  int c, state, len = 0, length_counter[100];
  for(int i = 0; i < 100; i++){
    length_counter[i] = 0;
  }
  state = IN;

  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n'){
      state = OUT;
      length_counter[len]++;
      len = 0;
    }else {
      len++;
      state = IN;
    }  
  }
  for(int i = 0; i < 100; i++){
    printf("%d : %d\n", i, length_counter[i]);
  }
  return 0;
}
