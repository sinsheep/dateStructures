#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
         int countSpace = 0;
         for(int i = 0; i < s.size(); i++){
             if(s[i]==' ') countSpace ++;
         }
         int old = s.size(), n;
         s.resize(old + countSpace * 2);
         n = s.size();
         while(n>old){
             if(s[old] == ' '){
                s[n--] = '0';
                s[n--] = '2';
                s[n] = '%';
             }else
                 s[n] = s[old];
             n--;
             old--;
         }
         return s;
    }
};
int main(){
    Solution* s = new Solution();
    cout<<s->replaceSpace("abc akdsj ajsdkfjl")<<endl;
    return 0;
}
