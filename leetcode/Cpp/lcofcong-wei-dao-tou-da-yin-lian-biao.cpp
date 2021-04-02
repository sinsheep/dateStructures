#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {

        vector<int> ans;
        dfs(head,ans);
        return ans;
    }
    void dfs(ListNode *head,vector<int>& ans){
        if(!head) return;
        dfs(head->next,ans);
        ans.push_back(head->val);
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
