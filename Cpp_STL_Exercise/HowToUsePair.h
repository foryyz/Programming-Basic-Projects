//
// Created by yyz on 2024/11/2.
//
#include <iostream>
#ifndef CPP_STL_LEARN_HOWTOUSEPAIR_H
#define CPP_STL_LEARN_HOWTOUSEPAIR_H

void pair_HowToUse_ALL(){
    //方式1 - 创建队组
    std::pair<std::string ,int> p("yyz",3);
    std::cout << p.first << "-" << p.second << std::endl;
    // 方式2
    std::pair<std::string, int> p2 = make_pair("ooo",10);
    std::cout << p2.first << "-" << p.second << std::endl;
}


#endif //CPP_STL_LEARN_HOWTOUSEPAIR_H
