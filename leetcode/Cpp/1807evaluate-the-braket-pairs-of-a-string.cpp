#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> m;
        for(int i = 0; i < knowledge.size();i++){
            m[knowledge[i][0]]=knowledge[i][1];
        }
        int flag=0;
        string n,tmp;
        for(int i = 0 ; i <s.size();i++){
            if(s[i]=='('){
                flag =1;
                continue;
            }
            if(s[i]==')'){
                flag=0;
                if(m[tmp]==""){
                    n+='?';
                }else n+=m[tmp];
                tmp="";
                continue;
            }
            if(flag){
                tmp+=s[i];
            }else{
                n+=s[i];
            }
        }
        return n;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
