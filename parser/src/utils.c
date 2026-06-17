#include <stdio.h>
#include <stdlib.h>
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
    return 0;
}

int pop() {
    if (buf_ptr > 0) {
        return buffer[--buf_ptr];
    } else {
        printf("Error: buffer is empty\n");
        return -1;
    }
}

int getch() {
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

int dcl(void) {
    int ns = 0;
    while (get_token() == '*') {
        ns++;
    }
    if (dirdcl() == -1) 
        return -1;
    for (;ns > 0;ns--) {
        strcat(out, "Pointer to ");
    }
    return 0;
}

int dirdcl(void) {
    int type;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("Error: expected ')'\n");
            return -1;
        }
    } else if (tokentype == NAME) {
        strcpy(name, token);
    } else {
        printf("Expected (dcl) or name\n");
        return -1;
    }
    while ((type = get_token()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat(out, "function returning ");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of ");
        }
    }
    return 0;
}

int reset() {
    int c;
    while ((c = getch()) != '\n' && c != EOF)
        ;
    out[0] = '\0';
    return 0;
}
