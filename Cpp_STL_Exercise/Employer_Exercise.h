//
// Created by yyz on 2024/11/2.
//

#ifndef CPP_STL_LEARN_EMPLOYER_EXERCISE_H
#define CPP_STL_LEARN_EMPLOYER_EXERCISE_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define A_E 0
#define B_E 1
#define C_E 2

class Employer{
public:
    string name_;
    int salary_;
};

void create_employers(vector<Employer>& employers){
    string names = "ABCDEFGHIJKLMN";
    int index = 0;
    for (char n : names) {
        Employer employer;
        employer.name_ = n;
        employer.salary_ = rand() % 10000+10000; // 随机数 10000~19999
        employers.push_back(employer);
        index ++;
    }
    cout << "添加" << index <<"个员工成功！" << endl;
}

void set_group(const vector<Employer>& employers, multimap<int, Employer>& mE){
    for(const auto& employer : employers){
        int dept_id = rand() % 3; // 0 1 2 随机数
        mE.insert(make_pair(dept_id,employer));

    }
}

void show_employers(multimap<int, Employer>& mE){
    multimap<int, Employer>::iterator pos = mE.find(A_E);
    int num = mE.count(A_E);
    int index = 0;
    cout << "A_E : "<<endl;
    for(; pos!=mE.end()&&index<num; pos++, index++){
        cout << "姓名" << pos->second.name_ << "-" << pos->second.salary_ << endl;
    }

    cout << "B_E : "<<endl;
    pos = mE.find(B_E);
    num = mE.count(B_E);
    index = 0;
    for(; pos!=mE.end()&&index<num; pos++, index++){
        cout << "姓名" << pos->second.name_ << "-" << pos->second.salary_ << endl;
    }

    cout << "C_E : "<<endl;
    pos = mE.find(C_E);
    num = mE.count(C_E);
    index = 0;
    for(; pos!=mE.end()&&index<num; pos++, index++){
        cout << "姓名" << pos->second.name_ << "-" << pos->second.salary_ << endl;
    }

}
void employer_exercise_main(){
    vector<Employer> employers;
    create_employers(employers);
    // 用来显示是否添加员工成功
    for(const auto& employer : employers){
        cout << employer.name_ << "-" << employer.salary_ << endl;
    }
    // 给员工分组
    multimap<int, Employer> mE;
    set_group(employers, mE);

    // 显示员工
    show_employers(mE);
}

#endif //CPP_STL_LEARN_EMPLOYER_EXERCISE_H
