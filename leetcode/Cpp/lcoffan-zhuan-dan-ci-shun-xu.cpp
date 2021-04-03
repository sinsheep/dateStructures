#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stack<string> q;
        string tmp;
        for(auto c: s){
            if(c==' '){
                if(tmp!="")
                q.push(tmp);
                tmp="";
            }else{
                tmp+=c;
            }
        }
        if(tmp!="")q.push(tmp);
        int n = 0;
        string ans;
        while(!q.empty()){
            if(n++)ans+=' ';
            ans +=q.top();
            q.pop();
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
