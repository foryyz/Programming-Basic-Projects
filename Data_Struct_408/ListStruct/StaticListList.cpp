#include <stdio.h>
#include <stdlib.h>

using namespace std;

// 静态链表
#define MAXSIZE 10
typedef struct{
    int data;   // 数据元素
    int next;   // 下一个元素的数组下标,可让-1表示为尾结点, -2表示为空闲
}SLinkList[MAXSIZE];

// 初始化静态链表

int main(int argc, char* argv[]){
    SLinkList sl;

    return 0;
}