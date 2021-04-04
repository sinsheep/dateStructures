#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        map<string,int> word;
        if(sentence1.size()>sentence2.size()){
            swap(sentence1,sentence2);
        }
        string tmp;
        int q = 0;
        for(int i = 0; i < sentence1.size(); i++){
            if(sentence1[i]==' '){
                if(word[tmp])q++;
                word[tmp] ++;
                tmp="";
            }else tmp+=sentence1[i];
        }
        if(tmp!="") word[tmp] = 1;
        tmp=""; int flag = 1, s=0,ws=0;
        for(int i = 0; i　< sentence2.size();i++){
            if(sentence2[i] == ' '){
                if(word.count(tmp)&&word[tmp]){
                    word[tmp]--;
                    flag = 1;    
                    ws++;
                }else{
                    if(flag)s++;
                    flag = 0;
                }
                tmp="";
            }else{
                tmp+=sentence2[i];
            }
        }
        
        if(tmp!=""){
            if(!word.count(tmp)&&flag)s++;
            if(word.count(tmp))ws++;
        }
        return ws==word.size()+q&&s<=1;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
