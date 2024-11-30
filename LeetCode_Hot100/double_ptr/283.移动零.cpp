#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while(right < n){
            if(nums[right]){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
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
