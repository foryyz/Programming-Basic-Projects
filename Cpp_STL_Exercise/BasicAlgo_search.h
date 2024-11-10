//
// Created by yyz on 2024/11/10.
//

#ifndef CPP_STL_LEARN_BASICALGO_SEARCH_H
#define CPP_STL_LEARN_BASICALGO_SEARCH_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Person5{
public:
    std::string name_;
    int age_;
    Person5(){}
    Person5(std::string name, int age){
        this->name_ = name;
        this->age_ = age;
    }
    // 重载 == ，底层find知道如何对比Person5数据类型
    bool operator==(const Person5& p){
        if (this->name_==p.name_ && this->age_==p.age_){
            return true;
        }
        return false;
    }
};

// find() 查找 Person5
void algo_HowToUse_find(){
    Person5 p;
    p.name_ = "yyz";
    p.age_ = 30;
    Person5 p2;
    p2.name_ = "www";
    p2.age_ = 20;
    Person5 p3;
    p3.name_ = "CC";
    p3.age_ = 13;
    std::vector<Person5> plist;
    plist.push_back(p);
    plist.push_back(p2);
    plist.push_back(p3);

    Person5 p5;
    p5.name_ = "yyz";
    p5.age_ = 30;

    if( std::find(plist.begin(), plist.end(), p5) == plist.end() ){
        std::cout << "没有找到" << std::endl;
    } else{
        std::cout << "找到了" << std::endl;
    }
}
// find_if() 查找 Person5
class AgeThree{ // 谓词，年龄大于3
public:
    bool operator()(const Person5& p){
        if (p.age_ > 3){ // 查找年龄大于3的人
            return true;
        }
        return false;
    }
};
void algo_HowToUse_findif(){
    Person5 p;
    p.name_ = "yyz";
    p.age_ = 0;
    Person5 p2;
    p2.name_ = "www";
    p2.age_ = 10;
    Person5 p3;
    p3.name_ = "CC";
    p3.age_ = 0;
    std::vector<Person5> plist;
    plist.push_back(p);
    plist.push_back(p2);
    plist.push_back(p3);

//    auto it=std::find_if(plist.begin(), plist.end(), GreaterThree());
//    if (it==plist.end()){
//        std::cout << "没找到" <<std::endl;
//    } else{
//        std::cout << "找到了" << it->name_ <<std::endl;
//    }
    // 遍历寻找所有符合条件的
    auto it=std::find_if(plist.begin(), plist.end(), AgeThree());
    for(;it!=plist.end();it=std::find_if(++it, plist.end(), AgeThree())){
        std::cout << "找到了" << it->name_ <<std::endl;
    }
}
// adjacent_find() 相邻重复元素查找
void algo_HowToUse_adjacent_find(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(5);
    auto it = std::adjacent_find(v.begin(),v.end());
    if (it == v.end()){
        std::cout << "未找到相邻重复元素" << std::endl;
    } else{
        std::cout << "找到了:" << *it << std::endl;
    }
}
// count() 统计
void algo_HowToUse_count(){
    std::vector<Person5> v;
    v.push_back(Person5("A",10));
    v.push_back(Person5("B",20));
    v.push_back(Person5("B",20));
    v.push_back(Person5("C",30));
    std::cout << "找到了" <<std::count(v.begin(),v.end(),Person5("B",20)) << "个B20";
}
// conut_if() 按条件统计
bool GreaterThree(int val){
    if (val > 3){
        return true;
    }
    return false;
}
void algo_HowToUse_countif(){
    std::vector<int> v;
    for (int i = 0; i < 9; ++i) {
        v.push_back(i);
    }
    for(const auto& i : v){
        std::cout << i;
    }
    std::cout << "一共找到" <<std::count_if(v.begin(),v.end(), GreaterThree) << "个大于3的数字" << std::endl;
}
#endif //CPP_STL_LEARN_BASICALGO_SEARCH_H
