#include <stdio.h>

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int j = 20;
    int i = 10;

    a[5] = 6; // 越界访问
    a[6] = 7;

    printf("i = %d\n", i);
    return 0;
}