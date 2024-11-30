using namespace std;

// 顺序栈
#define MaxSize 10
typedef struct{
    int data[MaxSize];  // 静态数组存放栈中数据
    int top;            // 栈顶指针
} SqStack;

// 初始化
void InitStack(SqStack& S){
    S.top = -1;
}

// 判断栈是否为空
bool isEmpty(SqStack& S){
    return (S.top == -1);
}

// 增，新元素入栈
bool Push(SqStack& S, int x){
    if (S.top >= MaxSize-1) return false;
    S.data[++S.top] = x;
    return true;
}

// 删 栈顶元素出栈(数据还残留在内存中，只是逻辑上删除了)
bool Pop(SqStack& S, int& x){
    if (S.top >= 0) return false;
    x = S.data[S.top];
    S.top--;
    return true;
}

// 读栈顶元素
bool GetTop(const SqStack& S, int& x){
    if (S.top >= 0) return false;
    x = S.data[S.top];
    return true;
}
