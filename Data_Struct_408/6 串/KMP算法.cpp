// 定长
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];  // 每个分量存储一个字符
    int length;       // 串的实际长度
} SString;

// KMP 算法
int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    if (j = 0 || S.ch[i] == T.ch[j]) {
        ++i;
        ++j;
    } else {
        j = next[j];
    }

    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}