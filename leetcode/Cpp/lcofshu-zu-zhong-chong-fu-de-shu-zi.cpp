#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i<nums.size();i++){
            if(m[nums[i]]){
                return nums[i];
            }
            m[nums[i]]++;
        }

        return -1;

    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
