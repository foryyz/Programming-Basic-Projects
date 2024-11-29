#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;



// 方式1. 自己写的 击败88%, 28ms执行时间
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        if (nums.size() == 0){
            return 0;
        }
        
        int sum = 1;
        int tmp = 0;
        int result = 1;
        for (int i = 1; i < cp.size(); i++){
            if (cp[i] - cp[tmp] == 1)
            {
                sum ++;
            }else if(cp[i] == cp[tmp]){
                NULL;
            }else{
                sum = 1;
            }
            tmp ++;
            if(sum > result){
                    result = sum;
                }
        }

        return result;
    }
};

// 方式2. 官方题解 哈希表
// https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num : nums){
            num_set.insert(num);
        }
        int longestStreak = 0;
        for(const int& num : num_set){
            if (!num_set.count(num-1)){ // 关键判断语句，判断容器内是否存在num-1的数字
                int currentNum = num;
                int currentStreak = 1;
                while (num_set.count(currentNum + 1)){
                    currentNum += 1;
                    currentStreak += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};