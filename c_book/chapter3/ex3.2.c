#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024
#define INPUT_FILENAME "input.txt"

void escape(char s[], char t[]) {
  int c;
  int len_s = 0;

  for (int i = 0; (c = t[i]) != '\0'; i++) {             
    switch (c) {
      case '\n' :
        s[len_s] = '\\';
        len_s++;
        s[len_s] = 'n';
        len_s++;
        break;
      case '\t' :
        s[len_s] = '\\';
        len_s++;
        s[len_s] = 't';
        len_s++;
        break;
      default:
        s[len_s] = c;
        len_s++;
        break;
    }
  }
  s[len_s] = '\0';
}

int main(int argc, char *argv[])
{
  FILE *file_pointer;
  int c;
  int i = 0;

  char source_buffer[MAX_BUFFER_SIZE];
  char escaped_buffer[MAX_BUFFER_SIZE * 2];

  file_pointer = fopen(INPUT_FILENAME, "r");

  if (file_pointer == NULL) {
    return EXIT_FAILURE;
  }
  
  while ((c = fgetc(file_pointer)) != EOF && i < MAX_BUFFER_SIZE - 1) {
    source_buffer[i] = c;
    i++;
  }
  source_buffer[i] = '\0';
  fclose(file_pointer);
  escape(escaped_buffer, source_buffer);
  printf("The original file is\n%s\n", source_buffer);
  printf("Processed file is\n%s\n", escaped_buffer);

  return EXIT_SUCCESS;
}
