//
// Created by yyz on 2024/11/1.
//
#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

class Player{
public:
    std::string name_;
    int score_;

    Player(std::string name, int score){
        this->name_ = name;
        this->score_ = score;
    }
};

// 创建5个选手
void create_player(std::vector<Player>& players){
    std::string player_list = "ABCDE";
    int score = 0;
    for (int i = 0; i < 5; ++i) {
        std::string name = "选手";
        name += player_list[i];
        Player player(name,score);
        players.push_back(player);
    }
}
// 打印选手列表
void Print_players(const std::vector<Player>& players){
    for(std::vector<Player>::const_iterator it=players.begin();it!=players.end();it++){
        std::cout << it->name_ << "-" << it->score_ << std::endl;
    }
}

// 评委打分
void set_score(std::vector<Player>& players){
    for(std::vector<Player>::iterator it=players.begin();it!=players.end();it++){
        // 将打分放入deque容器当中
        std::deque<int> deq;
        for (int i = 0; i < 10; ++i) {
            int score = rand() % 41 +60; //60~100的随机数
            deq.push_back(score);
        }
        std::sort(deq.begin(), deq.end());
        deq.pop_front();
        deq.pop_back();
        std::cout << "最后的评分列表为: [";
        int sum = 0;
        for(std::deque<int>::iterator dit=deq.begin();dit!=deq.end();dit++){
            std::cout << *dit << ", ";
            sum += *dit;
        }
        std::cout << "]" << std::endl;
        int avg = sum/deq.size();
        it->score_ = avg;
    }
}


// main
void player_exercise_main(){
    // 随机数种子
    srand((unsigned int)time(NULL));

    std::vector<Player> players;
    create_player(players);
    Print_players(players);
    set_score(players);
    Print_players(players);
}
