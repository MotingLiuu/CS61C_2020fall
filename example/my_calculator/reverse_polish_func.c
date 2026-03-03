#include "calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_to_int(char s[]) {
   if (strcmp(s, "sin") == 0) {
        return 1;
   } else if (strcmp(s, "cos") == 0) {
        return 2;
   } else if (strcmp(s, "pow") == 0) {
        return 3;
   } else if (strcmp(s, "pt") == 0) {
        return 4;
   } else if (strcmp(s, "sw") == 0) {
        return 5;
   } else if (strcmp(s, "cl") == 0) {
        return 6;
   } else if (strcmp(s, "du") == 0) {
        return 7;
   }
    return 0;
}