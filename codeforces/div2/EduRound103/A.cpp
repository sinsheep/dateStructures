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
int main(){
    ll t,n, k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll f=n/k; if(k<n){
            if(n%k)
            k=(f+1)*k;
            else
            k=f*k;
        }
        if(n<=k){
            ll d=k%n;
            if(d==0){
                cout<<k/n<<endl;
            }else{
                cout<<k/n+1<<endl;
            }
        }
    }
    return 0;
}

