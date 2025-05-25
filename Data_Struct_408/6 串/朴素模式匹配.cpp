// 定长
#define MAXLEN 255
typedef struct {
    char ch[MAXLEN];  // 每个分量存储一个字符
    int length;       // 串的实际长度
} SString;

int Index(SString S, SString T) {
    int i = 1, j = 1;
    while (i <= S.length && i <= T.length) {
        if (S.ch[i] == T.ch[i]) {
            ++i;
            ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length;
    } else {
        return 0;
    }
}