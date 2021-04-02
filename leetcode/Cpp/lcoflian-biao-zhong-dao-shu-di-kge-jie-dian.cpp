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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* former = head, *late = head;
        for(int i = 0;i < k; i++){
            former = former->next;
        }
        while(former){
            former = former->next;
            late = late->next;
        }
        return late;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
