#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int main(){
    int n, arr[105][105], b[105][105], dp[105];
    while (cin >> n){
        for (int i = 1; i <= n; i++){
            for(int j = 1; j <=n; j++){
                cin >> arr[i][j];
            }
        }
        int M = -0x3f3f3f3f;
        for (int i = 1; i <= n; i++){
            memset(b, 0, sizeof b);
            for(int j = i; j <=n; j++){
                for(int k = 1; k <= n; k++){
                    b[j][k] = arr[j][k] + b[j-1][k];
                }
                memset(dp,0,sizeof(dp));
                for(int p=1;p<=n;p++){
                    dp[p]=max(b[j][p],dp[p-1]+b[j][p]);
                    M=max(M,dp[p]);
                }

            }
        }
        cout << M <<endl;
    }
    return 0;
}

