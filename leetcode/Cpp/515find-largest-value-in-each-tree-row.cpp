#include <bits/stdc++.h>
using namespace std;

  // Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<pair<TreeNode*,int>> q;
        int dp[1000];
        for(int i = 0; i < 1000;i++){
            dp[i]=-2147483648;
        }
        int m = 0;
        if(root)
        q.push(make_pair(root,0));
        else
        return ans;
        while(!q.empty()){
            pair<TreeNode*,int> tmp;
            tmp = q.front();
            q.pop();
            if(tmp.first->left){
                q.push(make_pair(tmp.first->left,tmp.second+1));
            }
            if(tmp.first->right){
                q.push(make_pair(tmp.first->right,tmp.second+1));
            }
            dp[tmp.second] = max(dp[tmp.second], tmp.first->val);
            m = max(tmp.second,m);
        }
        for(int i = 0; i <= m; i++){
            ans.push_back(dp[i]);
        }
        return ans;
    }
};
int main(){
    int dp[1000];
    for(int i = 0; i < 1000; i++){
        dp[i]=-2147483648;
        cout<<dp[i]<<endl;
    }
    Solution* s = new Solution();
    return 0;
}
