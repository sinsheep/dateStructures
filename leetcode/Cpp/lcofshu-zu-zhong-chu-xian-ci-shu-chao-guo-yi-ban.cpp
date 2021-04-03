#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = -1;
        map<int,int> m;
        for(int i = 0; i  < nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]]>m[ans]){
                ans = nums[i];
            }
        }
        return ans;
    }
    int majorityElement2(vector<int>& nums) {
        int vote = 0, x;
        for(auto num:nums){
            if(vote == x) x = num;
            vote += x==num? 1:-1;
        }
        return x;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
