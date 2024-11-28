#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 单链表
typedef struct LNode
{
    int data;
    LNode* next;
}LNode, *LinkList;

/* 初始化 */
// 初始化不带头节点的单链表
void InitList(LinkList& L){
    L->next = NULL;
}
// 初始化带头节点的单链表
bool InitListFirst(LinkList &L){
    L = (LNode*) malloc(sizeof(LNode));
    if (L == NULL){ // 内存分配失败
        return false;
    }
    L->next = NULL;
    return true;
}

/* 插入 */
// 带头节点时 按位序插入
bool ListInsert(LinkList& L, int index, int e){
    if (index < 1){ // 插入位置不合理
        return false;
    }
    LNode* p = L;
    int i = 0;
    while (p!=NULL && index-1>i){ // 如果index-1>0 则不用查找
        p=p->next;
        i++;
    }
    if (p == NULL){ // 如果p在查找后找到的是NULL，说明插入位置超过了链表长度
        cout << "超出长度！" << endl;
        return false;
    }
    
    LNode* s = (LNode*) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 后插法 在p节点之后插入节点
bool InsertNextNode(LNode* p, int e){
    if (p == NULL){
        return false;
    }
    LNode *s = (LNode*) malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 前插法 在p节点之后插入节点，需要先找到p节点的前驱节点
bool InsertPriorNode(LNode *p, int e){
    if (p==NULL) return false; // 传入的参数不合理
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}
// 按位序删除 删除表L的第index个位置的元素，并用e返回删除元素的值
bool DelNode(LinkList L, int index, int& e){
    LNode* p = L;
    for (int i = 0; i < index-1; i++){
        p = p->next;
    }// 此时 p->next为要删除的节点
    if (p->next == NULL) return false;
    LNode* q = p->next;
    e = p->next->data;
    if(p->next->next == NULL){
        cout << "要删除的元素是最后一个元素" << endl;
        free(p->next);
        p->next = NULL;
    }else{
        p->next = p->next->next;
        free(q);
    }
    return true;
}
// 指定节点的删除 偷天换日
bool DelListPtr(LNode* del_p){
    if(del_p == NULL) return false;
    if(del_p->next != NULL){
        del_p->data = del_p->next->data;
        LNode* tmp = del_p->next;
        del_p->next = del_p->next->next;
        free(tmp);
        return true;
    }else{
        cout << "只能使用从头遍历的方法删除最后一个元素" << endl;
        return false;
    }
}

// 按位查找
LNode* GetElem(LinkList L, int index){
    if(L == NULL) return NULL;
    LNode* p = L;
    for (int i = 0; i < index; i++){
        p = p->next;
    }
    return p;
}
// 按值查找  s_data表示要搜查的数据
LNode* GetIndex(LinkList L, int s_data){
    if(L == NULL) return NULL;
    LNode* p = L->next;
    while (p != NULL){
        if (p->data == s_data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
// 获取链表的长度
int GetLength(LinkList L){
    if (L == NULL) return 0;
    LNode* p = L->next;
    int length = 0;
    while (p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

// 头插法
bool List_FrontInsert(LinkList L, int num){
    LNode* newNode = (LNode*)malloc(sizeof(LNode));
    if (L->next == NULL){ // 此时单链表为空
        L->next = newNode;
        newNode->data = num;
        newNode->next = NULL;
    }else{
        newNode->next = L->next;
        newNode->data = num;
        L->next = newNode;
    }
    return true;
}
// 考点 使用头插法逆置单链表
void ResortList(LinkList& L){
    LinkList newList = (LinkList)malloc(sizeof(LinkList));
    InitListFirst(newList);
    LNode* p_L = L->next;
    LNode* n_L = newList;
    while (p_L != NULL){
        List_FrontInsert(newList, p_L->data);
        // 对原链表进行清理
        LNode* tmp = p_L;
        p_L = p_L->next;
        free(tmp);
    }
    LinkList tmp_l = L;
    L = newList;
    free(tmp_l);
}

// 遍历打印
void PrintLinkList(const LinkList L){
    LNode* p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


int main(){
    LinkList l;
    InitListFirst(l);
    ListInsert(l,1,3);
    PrintLinkList(l);
    ListInsert(l,2,5);
    PrintLinkList(l);
    ListInsert(l,3,6);
    PrintLinkList(l);
    int e = 0;
    cout << l->data << endl; // 0
    cout << l->next->data << endl; // 1
    cout << l->next->next->data << endl; // 2
    cout << l->next->next->next->data << endl; // 3
    cout << endl;
    PrintLinkList(l);
    /* 删除功能 */
    // DelListPtr(l->next->next);
    // cout << "删除某中间元素成功！" << endl;
    // DelNode(l,2,e);
    // cout << "删除" << e << "成功！" << endl;
    // PrintLinkList(l);
    // DelNode(l,1,e);
    // cout << "删除" << e << "成功！" << endl;

    /* 查找功能 */
    int over = 0;
    cout << GetElem(l,1)->data;
    cout << GetElem(l,2)->data;
    cout << GetElem(l,3)->data;

    if (GetIndex(l,3)){
        cout << "查找的链表里面有3" << endl;
    }
    if (GetIndex(l,4)){
        cout << "查找的链表里面有4" << endl;
    }else{
        cout << "查找的链表里面没有4" << endl;
    }

    cout << "链表的长度为: " << GetLength(l) << endl;
    PrintLinkList(l);
    // ResortList(l);
    List_FrontInsert(l,1);
    List_FrontInsert(l,9);
    PrintLinkList(l);
    cout << "链表的长度为: " << GetLength(l) << endl;

    ResortList(l);
    cout << "置换后的列表：" << endl;
    PrintLinkList(l);

}