#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
const int mod=1e9+7;
int dp[1005][1005];
ll solve(int n){
    ll ans=1;
    for(ll i=1;i<=n;i++){
        ans*=i;
        ans%=mod;
    }
    return ans;
}
inline void init(){
    dp[0][0]=1;
    for(int i=1;i<=1000;i++){
        dp[i][0]=dp[i][i]=1;
        for(int j=1;j<i;j++){
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
        }
    }
}
int main(){
    ll t,n,k,arr[10005];
    cin>>t;
    init();
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        reverse(arr,arr+n);
        int m=0,s=0;
        for(int i=0;i<n;i++){
            if(arr[i]==arr[k-1]){
                m++;
                if(i<=k-1)s++;
            }
        }
        cout<<dp[m][s]<<endl;
    }
    return 0;
}
