//
// Created by yyz on 2024/11/10.
//

#ifndef CPP_STL_LEARN_BASICALGO_SORT_H
#define CPP_STL_LEARN_BASICALGO_SORT_H

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

// sort排序
// 谓词
bool DownSort(int v1, int v2){
    return v1>v2;
}
void algo_HowToUse_sort(){
    std::vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    std::sort(v.begin(),v.end(), std::greater<>());
    for(const auto& it : v){
        std::cout << it ;
    }
}
// 洗牌 random_shuffle
void algo_HowToUse_random_shuffle(){
    std::vector<int> v;
    v.push_back(2);
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);
    std::sort(v.begin(),v.end(), std::greater<>());
    for(const auto& it : v){
        std::cout << it ;
    }std::cout << std::endl;
    std::shuffle(v.begin(),v.end(), std::mt19937(std::random_device()()));
    for(const auto& it : v){
        std::cout << it ;
    }
}
// merge 合并
void algo_HowToUse_merge(){
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> vTarget;

    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
        v2.push_back(i+10);
    }
    vTarget.resize(v1.size()+v2.size());
    std::merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    for(const auto& it: vTarget){
        std::cout << it << " ";
    }
}
// reverse 反转
void algo_HowToUse_reverse(){
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for(const auto& it : v){
        std::cout << it;
    }
    std::cout << "已反转!" << std::endl;
    std::reverse(v.begin(), v.end());
    for(const auto& it : v){
        std::cout << it;
    }
}
#endif //CPP_STL_LEARN_BASICALGO_SORT_H
