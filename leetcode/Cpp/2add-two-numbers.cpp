#include <bits/stdc++.h>
using namespace std;
  // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr, *tail = nullptr;
        int pre = 0;
        while(l1 || l2){
            int num = (l1 ? l1->val:0 ) + (l2 ? l2->val:0)+ pre;
            if(!head){
                head = tail = new ListNode(num%10);
            }else{
                tail->next = new ListNode(num%10);
                tail = tail->next;
            }
            pre = num / 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(pre>0){
            tail->next = new ListNode(pre);
        }
        return head;
    }
    
};
int main(){
    Solution* s = new Solution();
    return 0;
}
