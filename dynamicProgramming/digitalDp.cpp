#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
ll dp[20][6],digit[30];
ll dfs(int pos,int pre,int sta,bool limit){
    if(pos==-1) return 1;
    if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
    ll sum=0;
    int top=limit ? digit[pos]:9;
    for(int i=0;i<=top;i++){
        if(pre==4&&i==9)continue;
        sum+=dfs(pos-1,i,i==4,limit&&i==digit[pos]);
    }
    if(!limit)dp[pos][sta]=sum;
    return sum;
}
int solve(int x){
    int cnt=0;
    while(x){
        digit[cnt++]=x%10;
        x/=10;
    }
    return dfs(cnt-1,0,0,true);
}
int main(){
    memset(dp,-1,sizeof dp);
    int t;
    cin>>t;
    while(t--){
        ll a;
        cin>>a;
        ll ans=solve(a);
        cout<<a-ans+1<<endl;
    }
    return 0;
}
