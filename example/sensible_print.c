#include <stdio.h>
#include <ctype.h> // for isprint()

#define MAX_LINE 80

int main() {
    int c, n = 0;
    while ((c = getchar()) != EOF) { 
        if (isprint(c)) {// isprint checks whether a char can be printed to the terminal
            putchar(c);
            n++;
        } else {
            printf("\\x%02X", c); // 不可见字符用16进制显示
            n += 4; // \xHH 一共4个字符
        }
        if (n >= MAX_LINE) {
            putchar('\n');
            n = 0;
        }
    }
    return 0;
}