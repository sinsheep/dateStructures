#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        int n = 0;
        level(root,0,n);
        vector<vector<int>> ans(n+1,vector<int>());

        dfs(root,ans,0);
        return ans;
    }
    void level(TreeNode* root,int n,int &l){
        if(!root) return ;
        l = max(n,l);
        if(root->left) level(root->left,n+1,l);
        if(root->right) level(root->right,n+1,l);
    }
    void dfs(TreeNode* root,vector<vector<int>>& ans,int n){
        if(!root) return ;
        ans[n].push_back(root->val);
        if(root->left) dfs(root->left,ans,n+1);
        if(root->right) dfs(root->right,ans,n+1);
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}

