#include "utils.h"
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    while (get_token() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
