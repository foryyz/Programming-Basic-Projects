#include <stdio.h>
#include <stdlib.h>

// 栈的中缀表达式转后缀表达式
#define MaxSize 15
typedef struct{
    char data[MaxSize];  // 数据
    int top;            // 栈顶指针
} SqStack;
// 初始化
void InitStack(SqStack& S){
    S.top = -1;
}
// 判断是否为空
bool isEmpty(const SqStack& S){
    return (S.top == -1);
}
// 新元素入栈
bool Push(SqStack& S, char e){
    if(S.top == MaxSize) return false; // 此时栈为空
    S.top ++;
    S.data[S.top] = e;
    return true;
}
// 出栈
bool Pop(SqStack& S, char& e){
    if (isEmpty(S)) return false;
    e = S.data[S.top];
    S.top--;
    return true;
}

char* midToBack(char str[], int length){
    for(int i=0; i<length; ++i){
        // 判断 是否为 操作数
        
        // 判断 是否为 界限符 ()

        // 判断 是否为 运算符 + - * /

    }
}