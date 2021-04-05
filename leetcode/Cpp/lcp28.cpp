#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size();i++){
            ans += upper_bound(nums.begin(),nums.end(),target-nums[i])-nums.begin();
            if(nums[i]*2<=target)ans--;
            ans%=2000000014;
        }
        return ans/2;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
