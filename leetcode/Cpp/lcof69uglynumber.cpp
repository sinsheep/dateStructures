#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[2000]={0,1}, a = 1, b = 1,c = 1;
        for(int i = 2; i<= n;i++){
            int s1 = dp[a]*2, s2=dp[b]*3, s3=dp[c]*5;
            dp[i]=min(s1,min(s2,s3));
            if(s1==dp[i])a++;
            if(s2==dp[i])b++;
            if(s3==dp[i])c++;
        }
        return dp[n];
    }
};
int main(){
    Solution* s = new Solution();
    cout<<s->nthUglyNumber(10)<<endl;
    return 0;
}
