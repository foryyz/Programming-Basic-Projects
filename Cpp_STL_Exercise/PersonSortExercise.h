//
// Created by yyz on 2024/11/2.
//
#include <string>
#include <iostream>
#include <list>

using namespace std;

#ifndef CPP_STL_LEARN_PERSONSORTEXERCISE_H
#define CPP_STL_LEARN_PERSONSORTEXERCISE_H

class Person3{
public:
    string name_;
    int age_;
    int height_;
    Person3(string name,int age,int height){
        this->name_ = name;
        this->age_ = age;
        this->height_ = height;
    }
};

// 指定排序规则
bool comparePerson(Person3& p1, Person3& p2){
    // 按照年龄升序
    if (p1.age_ == p2.age_){
        return p1.height_ < p2.height_;
    }
    return p1.age_ < p2.age_;
}

void person_sort_main(){
    Person3 p1("A",18,175);
    Person3 p2("B",20,176);
    Person3 p3("C",14,165);
    Person3 p4("D",35,190);
    Person3 p5("E",35,182);
    Person3 p6("F",18,192);

    list<Person3> L;
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    cout <<"排序前：" << endl;
    for(list<Person3>::iterator it=L.begin();it!=L.end();it++){
        cout << it->name_ << "-" << it->age_ << "-" << it->height_ << endl;
    }

    L.sort(comparePerson);
    cout <<"排序后：" << endl;
    for(list<Person3>::iterator it=L.begin();it!=L.end();it++){
        cout << it->name_ << "-" << it->age_ << "-" << it->height_ << endl;
    }
}

#endif //CPP_STL_LEARN_PERSONSORTEXERCISE_H
