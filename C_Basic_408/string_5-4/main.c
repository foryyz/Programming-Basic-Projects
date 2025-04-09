#include <stdio.h>
#include <string.h>

int main(void) {
    int len;

    char c[20];
    char d[100] = "world";

    gets(c);
    puts(c);

    printf("len C = %d\n", strlen(c));

    strcat(c, d); // 把 d 中的字符串拼接到 c 中
    puts(c);

    strcpy(c, d); // 把 d 中字符串 拷贝 到 c
    puts(c);

    int iscmp = strcmp(c, d); // 比较字符串大小 比较ASCII码 相等返回0 c>d返回正值 c<d返回负值
    printf("iscmp = %d\n", iscmp);
    return 0;
}