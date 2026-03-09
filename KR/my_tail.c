#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLINE 1000
#define DEFAULT_TAIL 10

int str2int(char *s) {
    int result = 0;
    while (*s != '\0') {
        result = result * 10 + *s - '0';
        s++;
    }
    return result;
}

int main(int argc, char *argv[]) {
    int tail_num = DEFAULT_TAIL;

    if (argc == 2 && argv[1][0] == '-') {
        tail_num = atoi(argv[1] + 1);
    } else if (argv > 2) {
        fprintf(stderr, "Usage: %s [-n]\n", argv[0]);
        return 1;
    }
    
    if (tail_num <= 0) {
        return 0;
    }
    
    char **lines = (char **)malloc(tail_num * sizeof(char *));
    if (lines == NULL) {
        fprintf(stderr, "Memorry allocation failed\n");
        return 1;
    }
    for (int i = 0; i < tail_num; i++) {
        lines[i] = (char *)malloc(MAXLINE * sizeof(char));
        if (lines[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }
    
    int count = 0;

    while (fgets(lines[count % tail_num], MAXLINE, stdin)) {
        count++;
    }
    
    int start;
    int print_count;
    
    if (count < tail_num) {
        start = 0;
        print_count = count;
    } else {
        start = count % tail_num;
        print_count = tail_num;
    }
    
    for (int i = 0; i < print_count; i++) {
        printf("%s", lines[(start + i) % tail_num]);
    }
    
    for (int i = 0; i < tail_num; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}