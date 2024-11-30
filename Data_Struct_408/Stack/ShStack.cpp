using namespace std;

// 共享栈
#define MaxSize 10  // 定义栈中元素的最大个数

typedef struct{
    int data[MaxSize];  // 静态数组存放数据
    // 栈满条件 top0+1 == top1;
    int top0;           // 0号栈 栈顶指针
    int top1;           // 1号栈 栈顶指针
} ShStack;

// 初始化
void InitStack(ShStack& S){
    S.top0 = -1;
    S.top1 = MaxSize;
}