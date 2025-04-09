#include <stdio.h>

// scanf 读取字符串操作
int main(void) {
    char c[10];
    scanf("%s", c);

    printf("%s\n", c);

    char c2[10];
    char d[10];
    scanf("%s%s",c2, d); // scanf %s读取字符串时 也会跳过空格 和 \n
    printf("c2 = %s\nd = %s\n", c2, d);

    fflush(stdin); // 要先清空标准输入缓冲区 不然gets函数会出现意外的错误
    // 可以使用gets函数快速 初始化 带空格的字符数组
    char e[20];
    gets(e);
    puts(e); // 等价于 printf("%s\n", e);

    return 0;
}