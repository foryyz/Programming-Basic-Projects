#include <stdlib.h>

// 定长
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];  // 每个分量存储一个字符
    int length;       // 串的实际长度
} SString;

// 动态长度
typedef struct {
    char* ch;  // 按串长分配存储区，ch指向串的基地址
    int length;
} HString;

// 取子串
bool SubString(SString& Sub, SString S, int pos, int len) {
    // 子串范围越界判断
    if (pos + len - 1 > S.length) {
        return false;
    }
    for (size_t i = pos; i < pos + len; i++) {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}

// 比较两个字符串
int StrCompare(SString S, SString T) {
    for (size_t i = 1; i <= S.length && i <= S.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

// 定位操作
int Index(SString S, SString T) {
    int i = 1, n = S.length, m = T.length;
    SString sub;
    while (i < n - m + 1) {
        SubString(sub, S, i, m);
        if (StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    return 0;
}

int main() {

    return 0;
}