#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 循环单链表
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode, *LinkList;

// 初始化循环单链表
void InitList(LinkList& L){
    L = (LNode*)malloc(sizeof(LNode));
    L->next = L;
}

// 判断是否为空
bool isEmpty(LinkList& L){
    return (L->next==L);
}

// 判断结点p是否为循环单链表的最后一个结点
bool isTail(LinkList& L, LNode* p){
    return (p->next == L);
}
