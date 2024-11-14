//
// Created by yyz on 2024/11/10.
//

#ifndef CPP_STL_LEARN_ALGO_FOREACH_H
#define CPP_STL_LEARN_ALGO_FOREACH_H

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void Print_int(T t){
    std::cout << t;
}

class MyPrint2{
public:
    void operator()(int val){
        std::cout << val;
    }
};
void algo_HowToUse_foreach(){
    std::vector<int> v;
    for (int i = 0; i < 9; ++i) {
        v.push_back(i);
    }
    std::for_each(v.begin(), v.end(), Print_int<int>);
    std::for_each(v.begin(), v.end(), MyPrint2());
}


// 使用transform函数
class Transform_origin{
public:
    int operator()(int val){
        return val;
    }
};

void algo_HowToUse_transform(){
    std::vector<int> v;
    for (int i = 0; i < 9; ++i) {
        v.push_back(i);
    }
    std::vector<int> vTarget; // 目标容器
    vTarget.resize(v.size()); // 开辟空间
    std::transform(v.begin(), v.end(), vTarget.begin(),Transform_origin());
    std::for_each(vTarget.begin(), vTarget.end(), Print_int<int>);
}


#endif //CPP_STL_LEARN_ALGO_FOREACH_H
