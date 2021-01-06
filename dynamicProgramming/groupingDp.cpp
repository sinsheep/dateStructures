#include<stdio.h>
#include<string.h>
#define mset(a,b) memset(a,b,sizeof(a) )
const int inf=0x3f3f3f3f;
int min(int a,int b){
    return a>b?b:a;
}
int main(){
    int n,dp[1005][1005],sum[1005],arr[1005];
    mset(dp,inf);
    sum[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        sum[i]=arr[i]+sum[i-1];
        dp[i][i]=0;
    }
    for(int len=1;len<=n-1;len++){
        for(int j=1;j+len<=n;j++){
            int end=j+len;
            for(int i=j;i<=end;i++){
                dp[j][end]=min(dp[j][end],dp[j][i]+dp[i+1][end]+sum[end]-sum[j-1]);
            }
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}
