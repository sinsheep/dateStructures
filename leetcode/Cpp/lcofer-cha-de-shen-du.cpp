#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root) return 0;
        queue<pair<TreeNode*,int>> q;
        int ans = 0;
        q.push(make_pair(root,0));
        while(!q.empty()){
            TreeNode* tmp = q.front().first;
            int t = q.front().second;
            ans = max(t,ans);
            if(tmp->left) q.push(make_pair(tmp->left,t+1));
            if(tmp->right) q.push(make_pair(tmp->right,t+1));
            q.pop();
        }
        return ans + 1;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
