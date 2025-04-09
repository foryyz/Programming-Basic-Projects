#include <iostream>

void m(int * &p, int *q) {
    p = q;
}

// 二级指针的写法 这两种方法效果一样
void m2(int * *p, int *q) {
    *p = q;
}

int main() {
    int* p = NULL;
    int i = 10;
    int* q = &i;

    m(p, q); // 引用的写法
    m2(&p, &i); // 二级指针的写法 这两种方法效果一样

    std::cout << *p << std::endl;

    return 0;
}
