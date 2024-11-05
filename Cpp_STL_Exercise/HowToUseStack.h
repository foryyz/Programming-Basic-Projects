//
// Created by yyz on 2024/11/2.
//
#include <iostream>
#include <string>
#include <stack>

#ifndef CPP_STL_LEARN_HOWTOUSESTACK_H
#define CPP_STL_LEARN_HOWTOUSESTACK_H

void stack_HowToUse_ALL(){
    std::stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    while(!stk.empty()){
        std::cout << stk.top() << std::endl;
        stk.pop();
    }
    std::cout << "stk.size() = " << stk.size() << std::endl;
}


#endif //CPP_STL_LEARN_HOWTOUSESTACK_H
