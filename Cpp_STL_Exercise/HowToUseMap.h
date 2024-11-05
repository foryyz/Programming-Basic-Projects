//
// Created by yyz on 2024/11/2.
//

#ifndef CPP_STL_LEARN_HOWTOUSEMAP_H
#define CPP_STL_LEARN_HOWTOUSEMAP_H

#include "map"
#include "iostream"
#include "string"
using namespace std;
void PringMap(const map<int,int>& m){
    for(map<int,int>::const_iterator it=m.begin();it!=m.end();it++){
        cout << "first-" << it->first << "\tsecond-" << it->second << endl;
    }
}
void map_HowToUse_create(){
    map<int,int> mp;
    mp.insert(pair<int,int>(1,10));
    mp.insert(pair<int,int>(3,30));
    mp.insert(pair<int,int>(2,20));
    PringMap(mp);

    // 拷贝构造
    map<int,int>mp2(mp);
    // =重载
    map<int,int> mp3;
    mp3 = mp;
    mp3.insert(pair<int,int>(9,99));

    cout << "mp.size() = " << mp.size() << endl;
    cout << "mp.empty() = " << mp.empty() << endl;
    mp.swap(mp3);
    cout << "交换成功!" << endl;
    PringMap(mp);

    mp.erase(1);
    PringMap(mp);
    cout << endl;
    mp.erase(++mp.begin());
    PringMap(mp);
    cout << "mp[2] = " << mp[2];
    mp.clear();
    cout << "已清空！"<< endl;
    PringMap(mp);
    mp[1] = 9;
    PringMap(mp);

}

// 利用仿函数 改变排序规则
class Gamer{
public:
    string name_;
    int age_;
    Gamer(string name, int age){
        this->name_ = name;
        this->age_ = age;
    }
};
class MyCompare_Gamer{
public:
    bool operator()(const Gamer& g1, const Gamer& g2) const{
        return g1.age_ < g2.age_;
    }
};
void PringMap(const map<Gamer, bool, MyCompare_Gamer>& m){
    for(map<Gamer ,bool, MyCompare_Gamer>::const_iterator it=m.begin();it!=m.end();it++){
        cout << "Gamer - " << it->first.name_ << ",age_"<<it->first.age_<<"\t";
        if (it->second){
            cout << "He is OP" << endl;
        } else{
            cout << "He is NOT OP" << endl;
        }
    }
}
void map_HowToUse_sort(){
    map<Gamer,bool,MyCompare_Gamer> m;
    m.insert(make_pair(Gamer("yyz",25), true));
    m.insert(make_pair(Gamer("a",99), false));
    PringMap(m);
}

#endif //CPP_STL_LEARN_HOWTOUSEMAP_H
