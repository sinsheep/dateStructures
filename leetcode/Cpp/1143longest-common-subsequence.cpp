#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();
    vector<vector<int>> ans(n+1,vector<int>(m+1));
    for(int i = 1; i <= n; i++){
            for(int j =1; j <= m; j++){
                if(text1[i-1]==text2[j-1]){
                    ans[i][j] = ans[i-1][j-1] +1;
                }else{
                    ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        return  ans[n][m];
    }
};
int main(){
    int a, b, c;
    string s1="abcd", s2 ="abcjkd";
    Solution* s = new Solution();
    cout<<s->longestCommonSubsequence(s1, s2)<<endl;
    return 0;
}
