#include<bits/stdc++.h>
using namespace std;
int m,n,dp[1000],w[1000],c[1000];
int main(){
  cin>>m>>n;
  for(int i=1;i<=n;i++)cin>>w[i]>>c[i];
  int ma=0;
  for(int i=1;i<=n;i++){
    for(int j=m;j>=w[i];j--){
      dp[j]=max(dp[j-w[i]]+c[i],dp[j]);
      ma=max(ma,dp[j]);
    }
  }
  cout<<ma<<endl;
}
