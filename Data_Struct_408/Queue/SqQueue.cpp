#include <stdlib.h>

using namespace std;

// 队列 的顺序存储实现
#define MaxSize 10
typedef struct
{
    int data[MaxSize];      // 用静态数组存放队列元素
    int front, rear;        // 队头指针和队尾指针(数组下标)，队尾指针指向的是下一个应该插入元素的位置
    // 注意：出题方式还可能为 队尾指针指向的是队尾元素。实际代码在最下方
} SqQueue;

// 初始化
void InitQueue(SqQueue& Q){
    Q.rear = Q.front = 0;   // 队头 队尾指针都指向0
}

// 判断是否为空
bool isEmpty(const SqQueue& Q){
    return (Q.rear == Q.front);
}

// 入队
bool EnQueue(SqQueue& Q, int e){
    if((Q.rear+1)%MaxSize == Q.front) return false; // 重点、此时队列已满，即队尾指针的下一个位置是队头时为满
    Q.data[Q.rear] = e; // 将e元素插入队尾
    Q.rear = (Q.rear+1) % MaxSize;           // 重点
    return true;
}

// 出队
bool DeQueue(SqQueue& Q, int& e){
    if (Q.rear == Q.front) return false; // 此时队列为空
    e = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    return true;
}

// 查  获取队头元素
bool GetHead(SqQueue Q, int& e){
    if (Q.rear == Q.front) return false; // 此时队列为空
    e = Q.data[Q.front];
    return true;
}

// 返回队列元素个数
int GetQueueSize(const SqQueue& Q){
    return (Q.rear+MaxSize-Q.front)%MaxSize;
}

// 解决会浪费1块内存的方式
// 原因：判断队列是否为空的方式是 Q.rear == Q.front, 那么如果是Q.size==10时，Q.rear也==Q.front，那么为了避免
    // 逻辑的冲突，队列的真实最大长度其实是 MaxSize - 1

// 为了解决这个问题，可以再为队列新增一个变量 - 队列长度。如下：
typedef struct
{
    int data[MaxSize];      // 用静态数组存放队列元素
    int front, rear;        // 队头指针和队尾指针(数组下标)，队尾指针应该指向的是下一个应该插入元素的位置
    int size;               // 队列当前长度
} SqQueue;

// 那么此时，队列为空的判断就变成了 size == 0; 队列为满也就是 size == MaxSize;

// 还有一个方式
typedef struct
{
    int data[MaxSize];      // 用静态数组存放队列元素
    int front, rear;        // 队头指针和队尾指针(数组下标)，队尾指针指向的是下一个应该插入元素的位置
    int tag;                // 队列上次执行的操作，tag=1表示刚刚插入成功，tag=0表示刚刚删除成功
} SqQueue;
// 那么此时，在插入最后一个元素时,tag的值更新为1, 而且Q.front=Q.rear;
// 则判断队列为空的方式就变为了 Q.front==Q.rear && tag==0; 判断已满的方式就为 Q.front==Q.rear && tag==1;


/* -------- --------- --------- ---------- --------*/
// 可能会考察到的方式,Q.rear指向队尾元素
typedef struct
{
    int data[MaxSize];
    int front, rear;        // 队尾指针指向的是队尾元素
    int size;
} SqQueue;
// 初始化
void InitSqQueue(SqQueue& Q){
    Q.front = Q.size = 0;
    Q.rear = MaxSize-1;
}
// 增
bool EnSqQueue(SqQueue& Q, int e){
    if (Q.front == Q.rear+1 && Q.size == MaxSize) return false; // 此时队列已满
    Q.rear = (Q.rear+1) % MaxSize;
    Q.data[Q.rear] = e;
    Q.size++;
    return true;
}
// 减
bool DeSqQueue(SqQueue& Q, int& e){
    if (Q.front == Q.rear+1 && Q.size == 0) return false; // 此时队列为空
    e = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    Q.size--;
    return true;
}
// 计算队列的长度
bool GetSize(const SqQueue& Q){
    return (Q.size);
}