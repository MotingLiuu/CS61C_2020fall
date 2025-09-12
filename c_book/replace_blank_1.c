#include <stdio.h>

int main(int argc, char *argv[])
{
  int c, pre = 'c';
  
  while((c = getchar()) != EOF){
    if(c != ' '){
      pre = c;
      putchar(c);
    }else{
      if(pre != ' '){
        putchar(c);
        pre = c;
      }   
    }
  }
  return 0;
}
