#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDifferentIntegers(string word) {
        string n;
        map<string, int> m;
        word+='#';
        int flag = 0, ans = 0,zf=0;
        for(int i = 0; i <word.size(); i++){
            if(isdigit(word[i])){
                if(word[i]=='0'&&!flag){
                    zf=1;
                    continue;
                }
                flag=1;
                n+=word[i];
            }else{
                if(zf&&n.size()==0){
                    n="0";
                }
                if(!flag&&n.size()==0)continue;
                if(!m[n]){
                    // cout<<"---"<<m[n]<<"---"<<n<<endl;
                    ans++;
                    m[n]=1;
                }
                n="";
                zf=0;
                flag=0;
            }
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
