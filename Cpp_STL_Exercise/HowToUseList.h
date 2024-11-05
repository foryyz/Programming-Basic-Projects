//
// Created by yyz on 2024/11/2.
//
#include <list>
#include <string>
#include <iostream>


#ifndef CPP_STL_LEARN_HOWTOUSELIST_H
#define CPP_STL_LEARN_HOWTOUSELIST_H

void PrintList(const std::list<int>& lst){
    for(std::list<int>::const_iterator it = lst.begin(); it!=lst.end();it++){
        std::cout << *it;
    }
    std::cout << std::endl;
}
// list容器构造函数
void list_HowToUse_create(){
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    PrintList(lst);

    std::list<int>::iterator it = lst.begin();
    std::list<int>lst2(++it,lst.end());
    PrintList(lst2);

    std::list<int>lst3(lst);
    PrintList(lst3);

    std::list<int>lst4(3,9);
    PrintList(lst4);
}
// list容器 赋值和呼唤
void list_HowToUse_assignAndSwap(){
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    PrintList(lst);

    std::list<int> lst2;
    lst2 = lst;
    PrintList(lst2);

    std::list<int> lst3;
    lst3.assign(++lst.begin(),lst.end());
    PrintList(lst3);

    std::list<int> lst4;
    lst4.assign(5,9);
    PrintList(lst4);

    // Swap
    std::list<int> lst5;
    lst5.push_back(10);
    lst5.push_back(20);
    lst5.push_back(30);
    std::cout << "lst5:";
    PrintList(lst5);
    std::cout << "lst:";
    PrintList(lst);
    lst.swap(lst5);
    std::cout << "已执行交换";
    std::cout << "lst5:";
    PrintList(lst5);
    std::cout << "lst:";
    PrintList(lst);
}
// list容器 插入
void list_HowToUse_insert(){
    std::list<int> lst;
    lst.push_back(2);
    lst.push_back(3);
    lst.push_front(1);
    PrintList(lst);
    lst.insert(lst.begin(),9);
    PrintList(lst);
    lst.insert(++lst.begin(),7);
    PrintList(lst);
    lst.erase(lst.begin());
    PrintList(lst);
    lst.erase(++lst.begin());
    PrintList(lst);
    lst.push_back(2);
    PrintList(lst);
    lst.remove(2);
    PrintList(lst);
}
// list容器 反转和排序
bool myCompare(int v1,int v2){
    // 降序 就让第一个数 > 第二个数
    return v1>v2;
}
void list_HowToUse_reverseAndSort(){
    std::list<int> lst;
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(1);
    lst.push_back(4);
    PrintList(lst);
    lst.reverse();
    std::cout << "已反转" << std::endl;
    PrintList(lst);
    lst.sort();
    std::cout << "已排序" << std::endl;
    PrintList(lst);
    lst.sort(myCompare);
    std::cout<< "回调函数排序 > " <<std::endl;
    PrintList(lst);
}
#endif //CPP_STL_LEARN_HOWTOUSELIST_H
