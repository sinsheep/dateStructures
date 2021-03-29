#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = nums[k], i = k, j = k,m = nums[k];
        while(true){
            if(j==nums.size() - 1 && i == 0)break;
            if(i>0){
                if(j == nums.size() -1 || nums[i - 1] > nums[j + 1] ){
                    i--;
                    m = min(m,nums[i]);
                    ans =  max(ans, m * (j - i + 1));
                    continue;
                }
                
            }
            if(j<nums.size()){
                if(i == 0 || nums[i - 1] <= nums[j + 1] ){
                    j++;
                    m = min(m,nums[j]);
                    // cout<<j << " "<<m<<endl;
                }
            }
            ans =  max(ans, m * (j - i + 1));
            // cout<<j<<" "<<i<<endl;
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    vector<int> nums = { 5,5,4,5,4,1,1,1 };
    cout<<s->maximumScore(nums, 5)<<endl;
    return 0;
}
