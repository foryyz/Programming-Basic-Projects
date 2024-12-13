
// 求n的阶乘
int GetFactorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    return( n * GetFactorial(n-1));
}

// 等差数列求和
int GetNumsSum(int n){
    if (n == 1) return 1;
    if (n == 0) return 0;
    return(n+GetNumsSum(n-1));
}
// 等差数列求和
int GetNumsSum(int n, int x){ // x为求和的最大轮数
    if (n == 1) return 1;
    if (n == 0) return 0;
    if (n == x) return 0;
    
    return(n+GetNumsSum(n-1,x));
}

// 对称矩阵的压缩存储 映射函数
// 行优先存储时  求对称矩阵压缩存储的 物理存储下标 (该函数以下标从0开始为例)
int GetPos(int x, int y){
    if(x <=0 || y <= 0) return -1;  // 矩阵从1开始
    // 传入的为矩阵的 a(x,y)
    // 则一维数组下标为 (x-1)! + y
    if (x < y) return (GetNumsSum(y-1) +x -1); // 这一行是为了将上三角区的下标映射为下三角区
    return (GetNumsSum(x-1) +y -1); // GetNumsSum(x-1) +y 即为求出第几个元素，再-1就是下标
}
// 列优先存储时  求对称矩阵压缩存储的 物理存储下标 (该函数以下标从0开始为例)
int GetPos(int i, int j, int n){ // n为行号
    if(i <=0 || j <= 0) return -1;  // 矩阵从1开始
    if (i < j){// 这一步是为了将上三角区的下标映射为下三角区
        int tmp = i;
        i = j;
        j = tmp;
    }; 
    return ( GetNumsSum(j-1, n-j+2) + (i-j) -1 ); //为求出第几个元素，再-1就是下标
}


// 三角矩阵的压缩存储 - 以下三角矩阵为例子 行优先
int GetPos(int i, int j){
    if (i < j) return -1; // -1代表三角矩阵内存的最后一个数据
    return (GetNumsSum(i-1) + j-1);
}