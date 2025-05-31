# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main(int argc, char *argv[]) {
    char c = getchar();
    if (strcmp(argv[0], "upper_to_lower")) {
        putchar(tolower(c));
    } else {
        putchar(toupper(c));
    }
}