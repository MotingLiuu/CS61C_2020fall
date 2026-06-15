#include <stdio.h>
#include <stdlib.h>
#define MAX_BUFFER_SIZE 100

char buffer[MAX_BUFFER_SIZE];
int buf_ptr = 0;

void push(char c) {
    if (buf_ptr < MAX_BUFFER_SIZE) {
        buffer[buf_ptr++] = c;
    }
}

char pop() {
    if (buf_ptr > 0) {
        return buffer[--buf_ptr];
    } else {
        printf("Error: buffer is empty\n");
        exit(1);
    }
}
