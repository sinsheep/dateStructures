#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            nums[i]=nums[i]-rev(nums[i]);
            m[nums[i]]++;
            
        }
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += m[nums[i]]-1;
            ans %=1000000007;
            m[nums[i]]--;
        }
        return ans;
    }
    int rev(int n){
        int ans = 0;
        while(n){
            ans =ans *10 + n%10;
            n/=10;
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
