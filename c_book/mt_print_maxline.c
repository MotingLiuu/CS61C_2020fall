#include <stdio.h>

#define MAXLEN 1000
#define EXIT_SUCCESS 0

int getnewline(char store[]){
  int c, len = 0;
  while ((c = getchar()) != EOF && c != '\n') {
   store[len] = c;
   len++;
  }
  store[len] = '\0';
  return len;
}

void copy(char line1[], char line2[]) {
  int line1_len = 0;
  for (int i = 0; i < MAXLEN && line2[i] != '\0'; i++) { 
    line1[i] = line2[i];
    line1_len++;
  }
  line1[line1_len] = '\0';
  line1_len++;
} 

int main(int argc, char *argv[])
{
  char max_line[MAXLEN], tmp_line[MAXLEN];
  int max_len = 0, tmp_len = 0;

  while ((tmp_len = getnewline(tmp_line)) != 0) {
    if (tmp_len > max_len) {
      copy(max_line, tmp_line);
     } 
  }

  printf("%s\n", max_line);
  return EXIT_SUCCESS;
}
