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
    TreeNode* mirrorTree(TreeNode* root) {
        reverse(root);
        return root;
    }
    void reverse(TreeNode* root){
        if(!root) return ;
        reverse(root->left);
        reverse(root->right);
        TreeNode* tmp  = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
