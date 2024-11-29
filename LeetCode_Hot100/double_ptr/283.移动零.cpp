#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto it = nums.begin();
        int zero_sum = 0;
        for(int i=0; i!=nums.size(); ++i){
            if (*it == 0){
                zero_sum ++;
                if (i == nums.size()-1){
                    nums.erase(it);
                    cout << "del this" << endl;
                    continue;;
                }
                it++;
                nums.erase(it-1);
                cout << "del priot" << endl;
                continue;
            }
        }
        cout << "0 del over" << endl;
        for(const auto& it : nums){
            cout << it << " ";
        }
        cout << endl;
        for (int i = 0; i < zero_sum; i++){
            nums.push_back(0);
        }
    }
};


int main(){
    vector<int> testv = {0,0,1};
    auto one = Solution();
    one.moveZeroes(testv);
    for(const auto& it : testv){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}