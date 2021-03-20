#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans;
        
        for(int i = 0; i < s.length(); i++){
            int a = 0, b = 0;
            for(int j = i; j < s.length(); j++){
                if(isupper(s[j])){
                    a |= 1 << (s[j] - 'A');
                }else{
                    b |= 1 << (s[j] - 'a');
                }
                if(a == b && j - i + 1> ans.length()){
                    ans = s.substr(i,j - i + 1);
                }
            }
        }
        return ans;
    }
};
