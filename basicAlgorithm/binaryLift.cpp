#include<iostream>
#define ll long long 
#define first fi
#define second se
#define inf 0x3f3f3f3f;
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
const int mod=1000000007;
int vi[1000005];
int go[50][1000005];
int sum[50][1000005],n,k,m;
int modadd(int a,int b){
    if(a+b>=mod)return a+b-mod;
    return a+b;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>vi[i];
    }
    for(int i=1;i<=n;i++){
        go[0][i]=(i+k)%mod+1;
        sum[0][i]=vi[i];
    }
    int logn=31-__builtin_clz(n);
    for(int i=1;i<=logn;i++){
        for(int j=1;j<=n;j++){
            go[i][j]=go[i-1][go[i-1][j]];
            sum[i][j]=modadd(sum[i-1][j],sum[i-1][go[i-1][j]]);
        }
    }
    cin>>m;
    int ans=0;
    int curx=0;
    for(int i=1;m;i++){
        if(m&(1<<i)){
            ans=modadd(ans,go[i][curx]);
            curx=go[i][curx];
        }
        m^=1<<i;
    }
    printf("%d",ans);
    return 0;
}


