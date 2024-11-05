//
// Created by yyz on 2024/11/2.
//
#include <set>
#include <iostream>

#ifndef CPP_STL_LEARN_HOWTOUSESET_H
#define CPP_STL_LEARN_HOWTOUSESET_H

using namespace std;
// 遍历容器set
void PrintSet(const set<int>& s){
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout << *it;
    }cout << endl;
}

// set构造函数
void set_HowToUse_ALL(){
    set<int> st;
    st.insert(1);
    st.insert(3);
    st.insert(2);
    st.insert(4);
    pair<set<int>::iterator ,bool> p = st.insert(1);
    if (p.second){
        cout << "输出为真，插入成功" << endl;
    } else{
        cout << "失败" << endl;
    }
    // 遍历容器
    for(set<int>::iterator it=st.begin();it!=st.end();it++){
        cout << *it;
    }cout << endl;

    set<int>::iterator sit = st.find(88);
    if (sit==st.end()){
        cout << "元素未找到"<<endl;
    }else{
        cout << "元素找到了" << endl;
    }
}

//利用仿函数更改set容器排序规则
class MyCompare{
public:
    bool operator() (int v1, int v2) const {
        return v1 > v2;
    }
};
void PrintSet(const set<int,MyCompare>& s){
    for(set<int>::iterator it=s.begin();it!=s.end();it++){
        cout << *it;
    }cout << endl;
}
void set_HowToUse_sort1(){
    set<int> s1;
    cout << "未改变排序规则 - s1: ";
    s1.insert(5);
    s1.insert(2);
    s1.insert(1);
    s1.insert(3);
    s1.insert(4);
    PrintSet(s1);

    set<int,MyCompare> s2;
    s2.insert(5);
    s2.insert(2);
    s2.insert(1);
    s2.insert(3);
    s2.insert(4);
    cout << "已改变排序规则 - s2: ";
    PrintSet(s2);
}
class Person4{
public:
    string name_;
    int age_;
    Person4(string name,int age){
        this->name_ = name;
        this->age_ = age;
    }
};

class comparePerson4{
public:
    bool operator()(const Person4& p1, const Person4& p2) const{
        // 按照年龄降序
        return p1.age_ > p2.age_;
    }
};

void set_HowToUse_sort2(){
    set<Person4,comparePerson4> s;
    Person4 p1("yyz",1);
    Person4 p2("AAA",2);
    Person4 p3("BBB",3);
    Person4 p4("CCC",4);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for(set<Person4,comparePerson4>::iterator it=s.begin();it!=s.end();it++){
        cout << it->name_ << "-" << it->age_ << endl;
    }
}
#endif //CPP_STL_LEARN_HOWTOUSESET_H
