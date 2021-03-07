#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, dp[10005], m;
int main(){

    cin >> n;
    m = (n * (n + 1)) / 2;
    dp[0] = 1;
    if(m % 2){
        cout << 0 << endl;
    }else {
        m /= 2;
        for (int i = 1; i <= n; i++) {
            for (int j = m; j>= i; j--){
                dp[j] += dp[j-i];
            }
        }
        cout<< dp[m]/2 << endl;
    }
    return 0;
}

