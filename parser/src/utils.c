#include <stdio.h>
#include "utils.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

char buffer[MAX_BUFFER_SIZE];
int buf_ptr = 0;

bool empty() {
    if (buf_ptr == 0) {
        return true;
    } else {
        return false;
    }
}

int push(char c) {
    if (buf_ptr < MAX_BUFFER_SIZE) {
        buffer[buf_ptr++] = c;
    } else {
        printf("Error: buffer is full\n");
        return -1;
    }
}

int pop() {
    if (buf_ptr > 0) {
        return buffer[--buf_ptr];
    } else {
        printf("Error: buffer is empty\n");
        return -1;
    }
}

char getch() {
    int c;
    if (empty()) {
        c = getchar();
        if (c == EOF) {
            return -1;
        }
    } else {
        c = pop();
    }
    return c;
}

void ungetch(char c) {
    push(c);
}

int get_token(void) {
    char *p = token;
    int c;
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else 
        return tokentype = c;
}


