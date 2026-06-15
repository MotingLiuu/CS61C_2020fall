#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void test_buffer() {
    push('a');
    push('b');
    char c = pop();
    if (c == 'b') {
        printf("test_buffer passed\n");
    } else {
        printf("test_buffer failed\n");
    }
}

void test_get_token() {
    printf("---------test_get_token---------\n");
    push(')');
    push('(');
    push('a');
    push('b');
    push('c');
    push(']');
    push('[');

    int datatype = get_token();
    if (strcmp(token, "[]") == 0 && datatype == BRACKETS) {
        printf("test_get_token 3rd part passed\n");
    }
    
    datatype = get_token();
    if (strcmp(token, "cba") == 0 && datatype == NAME) {
        printf("test_get_token 2nd part passed\n");
    }
    datatype = get_token();
    if (strcmp(token, "()") == 0 && datatype == PARENS) {
        printf("test_get_token 1st part passed\n");
    }
}


int main(int argc, char *argv[]) {
    test_buffer();
    test_get_token();
}
