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
const int M=200005;
ll gn[M], bn[M],g[M],bo[M];
int main(){
    ll t, a, b, k;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        memset(gn,0,sizeof(gn));
        memset(bn,0,sizeof(bn));
        for(int i=0;i<k;i++){
            cin>>bo[i];
            bn[bo[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>g[i];
            gn[g[i]]++;
        }
        ll ans=0;
        for(int i=0;i<k;i++){
            ll q=k-bn[bo[i]]-gn[g[i]]+1;
            // cout<<q<<endl;
            ans+=q;
        }
        cout<<ans/2<<endl;
    }
    return 0;
}

