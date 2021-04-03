#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int l = i + 1, r = nums.size() - 1; 
            while(l < r){
                int mid = (l + r) >> 1;
                if(nums[mid]>=target - nums[i]){
                    r = mid;
                }else{
                    l  = mid + 1;
                }
            }
            if(nums[r] + nums[i] == target){
                ans.push_back(nums[r]);
                ans.push_back(nums[i]);
                break;
            }
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
