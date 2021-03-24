#include<bits/stdc++.h>
using namespace std;
class Solution {
    int vis[20]={0};
public:
    void dfs(vector<int> &nums, vector<vector<int>> &ans,int pos,vector<int> tmp){
        if(pos == nums.size()){
            ans.push_back(tmp);
            return ;
        }
        for(int i = 0; i < nums.size(); i++){
            if(vis[i]||( i > 0 && nums[i]==nums[i-1]  && !vis[i-1])){
                continue ;
            }
            vis[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, ans, pos + 1, tmp);
            vis[i] = 0;
            tmp.pop_back();
        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, ans, 0, tmp);
        return ans;
    }
};
int main(){
    return 0;
}
