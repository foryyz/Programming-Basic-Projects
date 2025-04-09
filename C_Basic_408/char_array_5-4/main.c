#include <stdio.h>

int main(void) {
    // char c[5] = "hello"; // 这种写法是不对的 因为字符串后面要有一个\0
    char c[6] = "hello";
    printf("%s\n", c);

    char c2[5] = {'h','e','l','l','o'};
    printf("%s\n", c2);
    // 此时输出会有乱码 没有\0 结束符
    return 0;
}