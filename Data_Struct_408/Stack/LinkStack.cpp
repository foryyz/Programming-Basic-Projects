#include <stdlib.h>
#include <iostream>

using namespace std;

// 链栈
typedef struct LNode{
    int data;               // 数据域
    struct LNode *next;  // 指针域
}*LinkStack;

// 初始化 // 不带头结点的初始化
void InitStack(LinkStack& L){
    L = NULL;
}

// 判断是否为空
bool isEmpty(LinkStack& L){
    return (L == NULL);
}

// 增 进栈
bool Push(LinkStack& L, int e){
    LNode* s = (LNode*) malloc(sizeof(LNode));
    if(L != NULL){
        s->next = L;
    }
    L = s;
    s->data = e;
    return true;
}

// 删 出栈
bool Pop(LinkStack& L, int& e){
    if(L == NULL) return false;
    LNode* tmp = L;
    L = L->next;
    e = tmp->data;
    free(tmp);
    return true;
}


// 遍历
void PrintStack(const LinkStack& L){
    if (L == NULL) return;
    LNode* p = L;
    cout << " -> ";
    while (p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main(int argc, char* argv[]){
    LinkStack l;
    InitStack(l);
    Push(l,2);
    Push(l,4);
    Push(l,6);
    PrintStack(l);
    int e = 0;
    Pop(l, e);
    PrintStack(l);
    return 0;
}