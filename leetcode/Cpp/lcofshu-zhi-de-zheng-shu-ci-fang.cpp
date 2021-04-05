#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        bool negative = false;
        double base = x;
        if(n<0){
            n=-(n+1);
            negative = true;
        }
        double ans = 1;
        while(n){
            if(n&1) ans *=x;
            x*=x;
            n>>=1;
        }
        if(negative){
            ans = 1.0/(ans*base);
        }
        return ans;
    }
    
};
int main(){
    Solution* s = new Solution();
    return 0;
}
