#include <bits/stdc++.h>
#define doub(x) (x)*(x)
#define ll long long
using namespace std;
int main(){
  int l,s,m,t,stone[105],vis[4000],dp[2005];
  while(scanf("%d",&l)!=EOF){
    cin>>s>>t>>m;
    memset(vis,0,sizeof(vis));
    memset(dp,0x3f3f3f3f,sizeof(dp));
    stone[0]=0;
    for(int i=1;i<=m;i++){
      cin>>stone[i];
    }
    stone[m+1]=l;
    sort(stone,stone+m+2);
    int cnt=0;
    for(int i=1;i<=m+1;i++){
      if(stone[i]-stone[i-1]>=t) cnt+=(stone[i]-stone[i-1])%t+t;
      else cnt+=(stone[i]-stone[i-1]);
      vis[cnt]=1;
    }
    vis[cnt]=0,dp[0]=0,vis[0]=0;
    for(int i=1;i<=cnt+t-1;i++){
      for(int j=s;j<=t;j++){
        if(i-j>=0){
          dp[i]=min(dp[i],dp[i-j]+vis[i]);
        }
      }
    }
    int ms=0x3f3f3f3f;
    for(int i=cnt;i<=cnt+t-1;i++){
        ms=min(ms,dp[i]);
    }
    cout<<ms<<endl;
  }
  return 0;
}

