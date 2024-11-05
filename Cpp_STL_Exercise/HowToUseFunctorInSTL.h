//
// Created by yyz on 2024/11/2.
//

#ifndef CPP_STL_LEARN_HOWTOUSEFUNCTORINSTL_H
#define CPP_STL_LEARN_HOWTOUSEFUNCTORINSTL_H

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// negate 一元仿函数 取反
void functorInSTL_HowToUse_negate(){
    negate<int> n;
    cout << n(50);
}

// plus 二元仿函数 加法
void functorInSTL_HowToUse_plus(){
    plus<int> p;
    cout << p(10,20);
}

// greater 大于
class MyConpare3{
public:
    bool operator()(int v1, int v2){
        return v1>v2;
    }
};
void functorInSTL_HowToUse_greater(){
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(9);
    v.push_back(15);
    for(const auto& it : v){
        cout << it << " ";
    }cout << endl;

    // 使用自己写的 谓词实现降序规则
    std::sort(v.begin(), v.end(), MyConpare3());
    for(const auto& it : v){
        cout << it << " ";
    }cout << endl;

    // 使用内建函数 等效↑
    vector<int> v2 = v;
    std::sort(v2.begin(), v2.end(), greater<int>());
    for(const auto& it : v2){
        cout << it << " ";
    }cout << endl;
}

// logical_not 逻辑非 内建函数
void functorInSTL_HowToUse_logical_not(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);

    for(const auto& it : v){
        cout << it << " ";
    }cout << endl;

    // 利用逻辑非 将容器v 搬运到 容器v2中，并执行取反操作
    vector<bool> v2;
    // 算法transform 接受 被拷贝容器的迭代器begin和end,生成容器的迭代器begin,和一个仿函数
    v2.resize(v.size()); // 搬运前记得为新容器开辟空间
    transform(v.begin(),v.end(),v2.begin(), logical_not());
    for(const auto& it : v2){
        cout << it << " ";
    }cout << endl;
}

#endif //CPP_STL_LEARN_HOWTOUSEFUNCTORINSTL_H
