//
// Created by yyz on 2024/11/1.
//
#include <iostream>
#include <deque>
#include <algorithm>

#ifndef STL_TEST_HOWTOUSEDEQUE_H
#define STL_TEST_HOWTOUSEDEQUE_H

// deque容器 打印函数
void Print_deque(const std::deque<int>& deq){
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++) {
        std::cout << *it;
    }
    std::cout << std::endl;
}
// deque容器 构造函数
void deque_create(){
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_front(9); // 头插法
    for(std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++){
        std::cout << *it << std::endl;
    }
}
// deque容器 插入 删除 清空 数据存取
void deque_HowToUse_pushAndpop(){
    std::deque<int> deq;
    for (int i = 0; i < 10; ++i) {
        deq.push_back(i);
    }
    Print_deque(deq);
    deq.insert(deq.begin(),99);
    Print_deque(deq);
    deq.insert(deq.begin(),3,77);
    Print_deque(deq);
    deq.erase(deq.begin(),deq.begin()+3);
    Print_deque(deq);
    std::cout << "deq[2] = " << deq[2] << std::endl;
    std::cout << "deq.at(2) = " << deq.at(2) << std::endl;
    deq.clear();
    std::cout << "deq已清空！"<<std::endl;
    Print_deque(deq);

}
// deque容器 排序
void deque_HowToUse_sort(){
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_front(7);
    deq.push_front(9);
    deq.push_front(8);
    Print_deque(deq);
    std::sort(deq.begin(), deq.end());
    Print_deque(deq);
}


#endif //STL_TEST_HOWTOUSEDEQUE_H
