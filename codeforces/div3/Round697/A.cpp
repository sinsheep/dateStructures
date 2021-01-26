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
void check(ll x){
    
    while(x>1){
        if(x%2){cout<<"YES"<<endl;return;}
        x>>=1;
    }
    cout<<"NO"<<endl;
}
int main(){
    ll t, n;
    cin>>t;
    while(t--){
        cin>>n;
        check(n);
    }
    return 0;
}
