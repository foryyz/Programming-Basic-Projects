#include <iostream>
#include <vector>
#include <unordered_map>
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