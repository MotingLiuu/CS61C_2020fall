#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int test_buffer() {
    push('a');
    push('b');
    char c = pop();
    if (c == 'b') {
        printf("test_buffer passed\n");
        return 0;
    } else {
        printf("test_buffer failed\n");
        return 1;
    }
}

int main(int argc, char *argv[]) {
    test_buffer();
}
