#include<bits/stdc++.h>
using namespace std;
int dp[305][305][140];
int main(){
    int n,m,d,cost,atk,ans=0;
    cin>>n>>m>>d;
    for(int i=0;i<n;i++){
        cin>>atk>>cost;
        for(int j=d;j>=cost;j--){
            for(int k=1;k<=5;k++){
                dp[j][k][0]=max(dp[j][k][0],dp[j-cost][k-1][0]+atk);
                ans=max(ans,dp[j][k][0]);
            }
        }
    }
    for(int i=0;i<m;i++){
        cin>>atk>>cost;
        for(int j=d;j>=cost;j--){
            for(int k=1;k<=5;k++){
                for(int p=1;p<=k;p++){
                    dp[j][k][p]=max(dp[j-cost][k][p-1]+atk,dp[j][k][p]);
                    ans=max(ans,dp[j][k][p]);
                }
            }
        }
    }
    cout<<ans<<endl;
}
