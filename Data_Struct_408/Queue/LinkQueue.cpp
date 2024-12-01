#include <stdlib.h>

using namespace std;

// 队列 - 链式存储
typedef struct LinkNode{ // 链式队列 结点
    int data;       // 数据域
    struct LinkNode* next; // 指针域
};
typedef struct LinkQueue{ // 链式队列
    LinkNode *front, *rear; // 队列的队头 和 队尾 指针
};

/* --- 带头结点 --- */
// 带头结点的初始化
void InitQueue(LinkQueue& Q){
    Q.front = (LinkNode*)malloc(sizeof(LinkNode));
    Q.rear = Q.front;
    Q.front->next = NULL;
}
// 判断是否为空 - 带头结点
bool isEmpty(const LinkQueue& Q){
    return (Q.front == Q.rear); // 或者 return(Q.front->next == NULL)
}
// 入队 - 带头结点
void EnQueue(LinkQueue& Q, int e){
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;
    Q.rear->next = s;   // 新结点插入到rear之后
    Q.rear = s;
}
// 出队 - 带头结点
bool DeQueue(LinkQueue& Q, int& e){
    if(Q.front->next == NULL) return false; // 此时队列为空
    LinkNode* tmp = Q.front->next;
    e = tmp->data;
    Q.front->next = tmp->next;
    if(Q.rear == tmp){// 此时 出队的元素为最后一个元素，如果不执行这块代码，Q.rear指向的就是已经被释放的内存
        Q.rear = Q.front;
    }
    free(tmp);
    return true;
}
// 获取队列长度 - 带头结点
int GetLength(const LinkQueue& Q){
    if(Q.front == Q.rear) return 0;
    LinkNode* p = Q.front->next;
    int size = 0;
    while (p != Q.rear){
        size++;
        p = p->next;
    }
    return size;
}

/* --- 不带头结点 --- */
// 不带头结点的初始化
void InitQueue(LinkQueue& Q){
    Q.front = NULL;
    Q.rear = NULL;
}
// 判断是否为空 - 不带头结点
bool isEmpty(const LinkQueue& Q){
    return (Q.front == NULL);
}
// 入队 - 不带头结点
void EnQueue(LinkQueue& Q, int e){
    LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = e;
    s->next = NULL;

    if (Q.front == NULL){
        Q.front = s;
        Q.rear = s;
    }else{
        Q.rear->next = s;   // 新结点插入到rear结点之后
        Q.rear = s;         // 修改rear指针
    }
}
// 出队 - 不带头结点
bool DeQueue(LinkQueue& Q, int& e){
    if(Q.front == NULL) return false; // 此时队列为空
    e = Q.front->data;
    LinkNode* tmp = Q.front;
    Q.front = Q.front->next;
    if(Q.rear == tmp){
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(tmp);
    return true;
}
// 获取队列长度 - 不带头结点
int GetLength(const LinkQueue& Q){
    if (Q.front == NULL) return 0; // 此时队列为空
    LinkNode* p = Q.front;
    int size = 0;
    while (p != Q.rear){
        size++;
        p = p->next;
    }
    return size;
}