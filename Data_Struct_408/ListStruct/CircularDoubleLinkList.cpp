#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 循环双链表
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

// 初始化循环双链表
void InitDLinkList(DLinkList& L){
    L = (DNode*)malloc(sizeof(DNode));
    L->next = L;
    L->prior = L;
}

// 判断循环双链表是否为空
bool isEmpty(const DLinkList& L){
    return (L->next == NULL);
}
// 判断结点p是否为循环单链表的最后一个结点
bool isTail(DLinkList& L, DNode* p){
    return (p->next == L);
}
// 判断结点p是否为循环单链表的最后一个结点
bool isHead(DLinkList& L, DNode* p){
    return (p->prior == L);
}

// 插入 在p节点之后插入s结点
bool InsertNextDNode(DNode* p, DNode* s){
    s->next = p->next;
    s->prior = p;
    p->next->prior = s; // 对于循环双链表 不需要if (p->next != NULL) 
    p->next = s;
}

// 删除 删除p的后继节点q
bool DelNextDNode(DNode* p, DNode* q){
    p->next = q->next;
    q->next->prior = p;
    free(q);
}