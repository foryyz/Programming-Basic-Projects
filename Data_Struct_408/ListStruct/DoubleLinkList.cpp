#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 双链表
typedef struct DNode
{
    int data;
    struct DNode *prior, *next; // 前驱和后继指针
} DNode, *DLinkList;

// 初始化 带头节点的双链表
void InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    L->prior = NULL;
    L->next = NULL;
}
// 判断是否为空
bool isEmpty(const DLinkList &L)
{
    if (L->next == NULL){
        return true;
    }
    return false;
}

// 插入 在p节点后插入newNode节点
bool InsertNextNode(DNode *p, DNode *newNode)
{
    if (p == NULL || newNode == NULL) return false;
    newNode->prior = p;
    if (p->next == NULL){
        p->next->prior = newNode;
    }

    newNode->next = p->next;
    p->next = newNode;
}

// 删除 删除p的后继节点p.next
bool DelNextDNode(DNode *p){
    if (p == NULL) return false;
    DNode* q = p->next;
    if (q == NULL) return false;
    p->next = q->next;
    if (q->next != NULL){
        p->next->prior = p;
    }
    free(q);
    return true;
}

// 销毁 循环释放每一个节点
void DestoryList(DLinkList& L){
    while (L->next != NULL){
        DelNextDNode(L->next);
    }
    free(L);    // 释放头节点
    L=NULL;     // 头指针指向NULL
}

// 遍历
void PrintDLinkList(const DLinkList& L){
    DNode* p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}