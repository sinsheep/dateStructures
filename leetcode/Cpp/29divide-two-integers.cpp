#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int ans = 0;
        if(dividend == 0)return 0;
        if(divisor == INT_MIN){
            if(dividend == INT_MIN){
                return 1;
            }
            return 0;
        } 
        if(dividend == INT_MIN){
            if(divisor==-1){
                return INT_MAX;
            }
            if(divisor == 1)return INT_MIN;
            dividend+=abs(divisor);
            ans++;
        }
        int negative = 1;
        if(dividend<0)negative*=-1;
        if(divisor<0)negative*=-1;
        dividend = abs(dividend);
        divisor = abs(divisor);

        for(int i = 31; i>=0;i--){
            if(dividend>>i >=divisor){
                ans +=1<<i;
                dividend-=divisor<<i;
            }
        }
        return negative*ans;
    }
};
int main(){
    Solution* s = new Solution();
    return 0;
}
