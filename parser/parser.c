#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

char out[1000];

void dcl(void) {
    int ns;
    for (ns = 0; gettoken() == '*'; ns++) {
        ;
    }
    direct_dcl();
    while (ns > 0) {
        strcat(out, "pointer to");
    }
}

void direct_dcl(void) {}
