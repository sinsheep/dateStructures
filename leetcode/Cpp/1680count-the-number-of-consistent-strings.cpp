#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;
        for(int i = 0; i < allowed.size();i++){
            s.insert(allowed[i]);
        }
        int ans = 0;
        for(int i = 0; i < words.size();i++){
            bool flag =true;
            for(int j = 0; j < words[i].size(); j++){
                if(!s.count(words[i][j])){
                    flag = false;
                    break;
                }
            }
            if(flag ){
                ans ++;
            }
        }
        return ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
