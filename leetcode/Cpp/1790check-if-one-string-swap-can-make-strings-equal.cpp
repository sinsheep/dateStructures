#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int q[1000],m=0;
        for(int i = 0; i < s1.size();i++){
            if(s1[i] != s2[i]){
                q[m++]=i;
            }
        }
        if(m==0)return true;
        if(m!=2)return false;
        return s1[q[0]] == s2[q[1]] && s1[q[1]] == s2[q[0]];
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
