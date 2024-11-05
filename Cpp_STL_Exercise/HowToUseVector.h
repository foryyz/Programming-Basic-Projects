//
// Created by yyz on 2024/10/31.
//


#ifndef STL_TEST_HOWTOUSEVECTOR_H
#define STL_TEST_HOWTOUSEVECTOR_H

#include <iostream>
#include <vector>
#include <algorithm>


class Person{
public:
    std::string name_;
    int age_;

    Person(std::string name,int age){
        this->name_ = name;
        this->age_ = age;
    }
};

// vector容器的3种遍历方法 - 迭代器
void PrintSome(int v){
    std::cout << v << std::endl;
}
void vector_HowToUse_iterator(){
    std::vector<int> v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    // 遍历方法 1
    std::vector<int>::iterator itBegin = v.begin(); // 起始迭代器
    std::vector<int>::iterator itEnd = v.end(); // 结束迭代器，指向容器中最后一个元素的下一次
    std::cout << "遍历方法1" << std::endl;
    while (itBegin != itEnd){
        std::cout << *itBegin << std::endl;
        itBegin++;
    }
    std::cout << "遍历方法2" << std::endl;
    // 遍历方法 2 = 1
    for(std::vector<int>::iterator it = v.begin(); it!=v.end();it++){
        std::cout << *it << std::endl;
    }

    // 遍历方法 3
    std::cout << "遍历方法3" << std::endl;
    std::for_each(v.begin(),v.end(),PrintSome);
}
//vector容器插入对象的方法 & 迭代器的两种迭代方式
void vector_HotToUse_pushBack(){
    Person p1("yyz",12);
    Person p2("www",14);
    Person p3("yyz3",9);
    Person p4("yyz4",20);
    Person p5("ooo",33);

    //使用迭代器 迭代类对象
    std::vector<Person> v1;
    v1.push_back(p1);
    v1.push_back(p2);
    v1.push_back(p3);
    v1.push_back(p4);
    v1.push_back(p5);
    for(std::vector<Person>::iterator it=v1.begin(); it !=v1.end(); it++){
        std::cout << it->name_ << "-" << it->age_ << std::endl;
    }

    //使用迭代器 迭代指针对象
    std::vector<Person*> v2;
    v2.push_back(&p1);
    v2.push_back(&p2);
    v2.push_back(&p3);
    v2.push_back(&p4);
    v2.push_back(&p5);
    for(std::vector<Person*>::iterator it=v2.begin(); it !=v2.end(); it++){
        std::cout << (*it)->name_ << "-" << (*it)->age_ << std::endl;
    }
}
//vector嵌套vector
void vector_HowToUse_vectorBaby(){
    std::vector<std::vector<Person>> v;
    //创建小容器
    std::vector<Person> v1;
    std::vector<Person> v2;
    std::vector<Person> v3;
    std::vector<Person> v4;
    v1.push_back(Person("yyz",11));
    v1.push_back(Person("yyz2",12));
    v2.push_back(Person("BBB",22));
    v3.push_back(Person("CCC",33));
    v4.push_back(Person("DDD",44));

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (std::vector<std::vector<Person>>::iterator it=v.begin(); it!=v.end();it++) {
        for(auto vit = it->begin();vit != it->end();vit++){ // auto使用自动类型推导 原本类型应该是std::vector<Person>::iterator
            std::cout << vit->name_ << "-" << vit->age_ << std::endl;
        }
    }
}
//vector的插入方法insert()
void vector_HowToUse_insert(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.insert(v.begin(),9);
    v.insert(v.begin()+1,99);
    v.insert(v.end(),999);
    v.insert(v.begin(),3,9999);
    for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
        std::cout << *it << std::endl;
    }
}
//vector的删除方法erase()
void vector_HowToUse_erase(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.erase(v.begin());
    for (std::vector<int>::iterator it = v.begin() ; it != v.end(); it++) {
        std::cout << *it << std::endl;
    }
}
//vector的数据存取方法
void vector_HowToGetData(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    int num = 2;
    std::cout << "v.front() = " <<v.front() << std::endl;
    std::cout << "v.at(num) = " << v.at(2) << std::endl;
    std::cout << "v[num] = " << v[2] << std::endl;
    std::cout << "v.back() = " << v.back() << std::endl;
}
//vector 交换方法swap()
void vector_HowToUse_swap_test1(){
    std::vector<int> v1;
    std::vector<int> v2;
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    for(std::vector<int>::iterator it = v1.begin(); it!= v1.end(); it++){
        std::cout << *it;
    }
    std::cout << " v1" << std::endl;

    for (int i = 9; i >= 0; --i) {
        v2.push_back(i);
    }
    for(std::vector<int>::iterator it = v2.begin(); it!= v2.end(); it++){
        std::cout << *it;
    }
    std::cout << " v2" << std::endl;

    v1.swap(v2);
    std::cout << "执行swap" <<std::endl;

    for(std::vector<int>::iterator it = v1.begin(); it!= v1.end(); it++){
        std::cout << *it;
    }
    std::cout << " v1" << std::endl;
    for(std::vector<int>::iterator it = v2.begin(); it!= v2.end(); it++){
        std::cout << *it;
    }
    std::cout << " v2" << std::endl;


}
//vector 使用交换方法和匿名对象节省内存
void vector_HowToUse_swap_test2(){
    std::vector<int> v;
    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);
    }
    std::cout << "存入了10000个数字" << std::endl;
    std::cout << "v的容量是 - " << v.capacity() << std::endl;
    std::cout << "v的大小是 - " << v.size() << std::endl;

    v.resize(3);
    std::cout << "重新设置大小后，v的容量是 - " << v.capacity() << std::endl;
    std::cout << "重新设置大小后，v的大小是 - " << v.size() << std::endl;

    std::vector<int>(v).swap(v);
    std::cout << "执行交换后，v的容量是 - " << v.capacity() << std::endl;
    std::cout << "执行交换后，v的大小是 - " << v.size() << std::endl;
}
//vector 预留空间 reserve()方法
void vector_HowToUse_reserve(){
    std::vector<int> v1;
    int num = 0;//统计重新开辟内存的次数
    int *p = NULL;
    for (int i = 0; i < 100; ++i) {
        v1.push_back(i);
        if (p!=&v1[0]){ // 如果检测到指针地址变动了就num++
            p = &v1[0]; // 更新p为拓展后的vector地址
            num++;
        }
    }
    std::cout << "v1的内存开辟了"<<num<<"次"<<std::endl;
    //预留空间
    std::vector<int> v2;
    v2.resize(1000);
    int num2 = 0;//统计重新开辟内存的次数
    int *p2 = NULL;
    for (int i = 0; i < 100; ++i) {
        v2.push_back(i);
        if (p2!=&v2[0]){ // 如果检测到指针地址变动了就num++
            p2 = &v2[0];
            num2++;
        }
    }
    std::cout << "v2的内存开辟了"<<num2<<"次"<<std::endl;
}

#endif //STL_TEST_HOWTOUSEVECTOR_H
