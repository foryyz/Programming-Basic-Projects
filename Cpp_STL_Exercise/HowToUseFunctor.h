//
// Created by yyz on 2024/11/2.
//

#ifndef CPP_STL_LEARN_HOWTOUSEFUNCTOR_H
#define CPP_STL_LEARN_HOWTOUSEFUNCTOR_H

#include <iostream>

using namespace std;

class MyAdd{
public:

    int operator()(int v1, int v2){
        return v1+v2;
    }
};

class MyPrint{
public:
    int count; // 内部自己的状态
    MyPrint(){
        this->count = 0;
    }
    void operator()(string test){
        cout << test << endl;
        this->count ++;
    }
};
void do_Print(MyPrint& myPrint,string str){
    myPrint(str);
}
void functor_HowToUse_create(){
    MyAdd myAdd;
    cout << myAdd(10,10) << endl;

    MyPrint myPrint;
    myPrint("hello");
    myPrint("hello");
    myPrint("hello");
    myPrint("hello");
    cout << "myPrint调用的次数为" << myPrint.count << endl; // 仿函数的特性，可以有自己的属性
    // 仿函数的特性，可以作为参数传递给函数
    do_Print(myPrint,"你好");
}

#endif //CPP_STL_LEARN_HOWTOUSEFUNCTOR_H
