#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal)
    {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return (abs(sum - goal) + limit - 1) / limit;
    }
};

int main()
{
    Solution* s = new Solution();
    return 0;
}
