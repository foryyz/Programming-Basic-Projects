#include <stdio.h>

int main(void) {
    int i;
    scanf("%d", &i);
    printf("i = %d\n", i);
    // 此时如果不清空标准输入缓冲区，那么上面的\n会保留并直接被 c 读取

    fflush(stdin); // 清空标准输入缓冲区
    char c;
    scanf("%c", &c);
    printf("c = %c\n", c);

    // scanf函数 在读取 整型 浮点 字符串 时 会忽略 \n 空格等
    float f;
    scanf("%f", &f);
    printf("f = %f\n", f);

    // scanf函数一次读多种数据类型
    int i2,ret;
    float f2;
    char c2;

    ret = scanf("%d %c%f", &i2, &c2, &f2); // ret 的值为 scanf函数匹配数值的个数
    // ret = scanf("%d%f%c", &i2, &f2, &c2); // 这种写法是错误的 多个输入时 %c 之前要有空格
    printf("i = %d, c = %c, f = %f\n", i2, c2, f2);
    return 0;
}