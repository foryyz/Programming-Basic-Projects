//
// Created by yyz on 2024/11/2.
//
#include <string>
#include <iostream>
#include <queue>

#ifndef CPP_STL_LEARN_HOWTOUSEQUEUE_H
#define CPP_STL_LEARN_HOWTOUSEQUEUE_H

class Person2{
public:
    std::string name_;
    int age_;

    Person2(std::string name,int age){
        this->name_ = name;
        this->age_ = age;
    }
};

void queue_HowToUse_ALL(){
    std::queue<Person2> que;

    //入队
    que.push(Person2("yyz",10));
    que.push(Person2("ooo",20));
    que.push(Person2("jjj",30));
    que.push(Person2("ppp",99));

    while(!que.empty()){
        std::cout << "que.front()" << que.front().name_ << std::endl;
        std::cout << "que.back()" << que.back().name_ << std::endl;

        que.pop();
    }
    std::cout << que.size();
}

#endif //CPP_STL_LEARN_HOWTOUSEQUEUE_H
