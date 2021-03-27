#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        s.push(0);
        for(auto c:S){
            if(c == '('){
                s.push(0);
            }else {
                int v = s.top(); s.pop();
                int w = s.top(); s.pop();
                s.push(w + max(v*2,1));
            }
        }
        return s.top();
    }
};
int main(){
    Solution* s = new Solution();
    string str = "(()(()()))";
    // string str = "()(()())";
    cout << s->scoreOfParentheses(str) << endl;
    return 0;
}
