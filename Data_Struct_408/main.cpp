#include <iostream>

using namespace std;

// 等差数列求和
int GetNumsSum(int n, int x){ // x为求和的最大轮数
    if (n == 1) return 1;
    if (n == 0) return 0;
    if (n == x) return 0;
    
    return(n+GetNumsSum(n-1,x));
}

// 列优先存储时  求对称矩阵压缩存储的 物理存储下标 (该函数以下标从0开始为例)
int GetPos(int i, int j, int n){ // n为行号
    if(i <=0 || j <= 0) return -1;  // 矩阵从1开始
    if (i < j){// 这一步是为了将上三角区的下标映射为下三角区
        int tmp = i;
        i = j;
        j = tmp;
    }; 
    cout << "算出列个数" << GetNumsSum(j-1, n-j+2) << "\t";
    return ( GetNumsSum(n, n-j+2) + (i-j)  ); //为求出第几个元素，再-1就是下标
}

int main(){
    cout << GetPos(0,0,5) << endl;
    cout << GetPos(3,2,5) << endl;
    cout << GetPos(4,2,5) << endl;
    cout << GetPos(5,5,5) << endl;
    // cout << GetNumsSum(4,2) << endl;
    return 0;
}