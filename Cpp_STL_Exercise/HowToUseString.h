//
// Created by yyz on 2024/10/31.
//

#ifndef STL_TEST_HOWTOUSESTRING_H
#define STL_TEST_HOWTOUSESTRING_H

#include <string>
#include <iostream>

// String容器的find()方法和substr()方法
void string_HowToUsefindAndsubstr_test(){
    std::string str = "hello@qq.com";
    int index = str.find('@');
    std::cout << "username = " << str.substr(0,index) << std::endl;
    std::cout << str.substr(index) << std::endl;
}

#endif //STL_TEST_HOWTOUSESTRING_H
