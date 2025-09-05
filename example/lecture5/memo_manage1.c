#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, *q, x;
    int a[4];
    p = (int *) malloc(sizeof(int));
    q = &x;
    *p = 1;
    *q = 2;
    *a = 3;
    printf("%d %d %d\n", *p, *q, *a);
    printf("%p %p %p\n", p, q, a);
    printf("%p %p %p\n", &p, &q, &a);
}