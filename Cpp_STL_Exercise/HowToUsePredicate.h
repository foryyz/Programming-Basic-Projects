//
// Created by yyz on 2024/11/2.
//

#ifndef CPP_STL_LEARN_HOWTOUSEPREDICATE_H
#define CPP_STL_LEARN_HOWTOUSEPREDICATE_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 一元谓词
class GreaterFive{
public:
    bool operator()(int val){
        return val>5;
    }
};
void predicate_HowToUse_One(){
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    // 查找容器中 有没有大于5的数字
    // GreaterFive() 匿名函数对象
    auto it = find_if(v.begin(),v.end(),GreaterFive());
    if (it != v.end()){
        cout << "找到了>5的数值：" << *it  << endl;
    }else{
        cout << *it << " <5" << endl;
    }
}

// 二元谓词
class MyCompare2{
public:
    bool operator()(int v1, int v2){
        return v1>v2;
    }
};
void predicate_HowToUse_Two(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    std::sort(v.begin(), v.end());
    for(vector<int>::iterator it=v.begin();it!=v.end();++it){
        cout << *it << " ";
    }cout << endl;

    // 使用函数对象 改变算法策略，变为排序规则为从大到小
    std::sort(v.begin(), v.end(), MyCompare2());
    for(vector<int>::iterator it=v.begin();it!=v.end();++it){
        cout << *it << " ";
    }cout << endl;
}

#endif //CPP_STL_LEARN_HOWTOUSEPREDICATE_H
