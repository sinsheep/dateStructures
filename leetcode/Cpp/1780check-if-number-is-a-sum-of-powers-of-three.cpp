#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPowersOfThree(int n) {
        if(n == 1) return true;
        while(n){
            if(n%3 >= 2){
                return false;
            }
            n/=3;
        }
        return true;
    }
};
int main(){
    Solution* s = new Solution();
    cout<<(s->checkPowersOfThree(21))<<endl;
    return 0;
}
