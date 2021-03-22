#include <bits/stdc++.h>
#define ll long long
#define mset(a) memset(a, 0, sizeof(a))
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        int dp[505]={0};
        dp[1] = nums[0];
        for(int i = 2; i <= l; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[l];
    }
};
int main(){
    return 0;
}


