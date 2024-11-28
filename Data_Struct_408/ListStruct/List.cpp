#include <stdio.h>
#include <stdlib.h>

// 顺序表

// 1. 静态分配实现
#define MaxSize 10 // 定义最大长度
typedef struct
{
    int data[MaxSize];
    int length;
}SqList;
// 初始化 顺序表
void InitList(SqList &L){
    for (size_t i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}
// 插入
bool ListInsert(SqList& L, int index, int e){
    if (L.length >= MaxSize){
        return false;
    }
    if (index > L.length+1 || index < 1){
        return false;
    }
    
    for (size_t i = L.length; i >= index; i--){
        L.data[i] = L.data[i-1];
    }
    L.data[index-1] = e;
    L.length ++;
    return true;
}
// 删除 用e来把结果带回来
bool ListDel(SqList& L, int index, int& e){
    if (L.length <= 0){
        return false;
    }
    if (index > L.length+1 || index < 1){
        return false;
    }
    e = L.data[index-1];
    for (size_t i = index; i < L.length; i++)
    {
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return true;
}
// 按位查找
int GetListIndex(SqList& L, int index){
    int result = -1;
    if (index >= 1 || index < L.length)
    {
        result = L.data[index-1];
    }
    return result;
}
// 按之查找
int GetListVar(SqList& L, int var){
    for (size_t i = 0; i < L.length; i++)
    {
        if (L.data[i] == var)
        {
            return i+1;
        }
    }
    return -1;
}
// 2. 动态分配内存
#define InitSize 10 // 定义初始长度
typedef struct
{
    int* data;
    int maxsize;
    int length;
}SeqList;

// 初始化 动态顺序表
void InitList(SeqList &L){
    L.data = (int*) malloc(InitSize*sizeof(int));
    L.length = 0;
    L.maxsize = InitSize;
}
// 增加动态数组的长度 增加len长度
void IncreaseSize(SeqList& L, int len){
    int *p = L.data;
    L.data=(int*) malloc((L.maxsize+len) * sizeof(int));
    for (size_t i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.maxsize += len;
    // delete p;
    free(p);
}

int main(){
    SqList L;
    InitList(L);
    L.data[0] = 1;
    L.length = 1;
    for (size_t i = 0; i < L.length; i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
    ListInsert(L,1,4);
    ListInsert(L,2,3);
    for (size_t i = 0; i < L.length; i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
    int e = -1;
    ListDel(L,1,e);
    for (size_t i = 0; i < L.length; i++)
    {
        printf("%d",L.data[i]);
    }
    printf("\n");
    printf("删除了：%d\n",e);
    int getindex = GetListIndex(L,1);
    int getvar = GetListVar(L,3);
    printf("按位查找1 : 值为%d\n按值查找3 ： 位置在%d\n",getindex,getvar);

    SeqList L2;
    InitList(L2);
    IncreaseSize(L2,3);

    return 0;
}