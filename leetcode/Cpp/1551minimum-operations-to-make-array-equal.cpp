#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(2*i + 1 > n){
                ans += 2*i +1 -n;
            }
        }
        return ans;
    }
};
int main(){
    
}
