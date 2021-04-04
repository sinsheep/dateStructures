#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;int n = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i]!=' '){
                ans += s[i];
            }
            if(s[i]==' '||i==s.size()-1){
                n++;
                if(n==k)break;
                ans+=' ';
            }
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
