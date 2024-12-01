#include <stdio.h>
#include <stdlib.h>

// 栈的括号匹配应用
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

bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);
    for(int i=0; i<length; ++i){
        if (str[i]=='(' || str[i]=='{' || str[i]=='['){
            Push(S, str[i]);
        }else{
            if (isEmpty(S)){
                return false; // 已扫描到右括号但当前栈为空
            }
            char topElem;
            Pop(S, topElem);
            if(topElem=='(' && str[i]!=')') return false;
            if(topElem=='{' && str[i]!='}') return false;
            if(topElem=='[' && str[i]!=']') return false;
        }
    }
    return isEmpty(S); // 最后还要判断栈是否排空了
}

int main(int argc, char const *argv[])
{
    char str[] = {'(','(','{','}',')',')'};
    if (bracketCheck(str, 6)) printf("匹配成功!\n");
    else printf("匹配失败!\n");

    char str1[]{'}','(','{','}',')',')'};
    if (bracketCheck(str1, 6)) printf("匹配成功!\n");
    else printf("匹配失败!\n");

    char str2[]{'(','{','{','}',')',')'};
    if (bracketCheck(str2, 6)) printf("匹配成功!\n");
    else printf("匹配失败!\n");

    char str3[]{'(','(','{','}',')'};
    if (bracketCheck(str3, 5)) printf("匹配成功!\n");
    else printf("匹配失败!\n");

    // ( ( { } [ ] ) )
    char str4[]{'(','(','{','}',')','[',']',')'};
    if (bracketCheck(str4, 8)) printf("匹配成功!\n");
    else printf("匹配失败!\n");

    return 0;
}
