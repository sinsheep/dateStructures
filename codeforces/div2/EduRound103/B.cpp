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
    ll t,n;
    ll k, arr[2000];
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll s=0, cnt=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i=1;i<n;i++){
            s+=arr[i-1];
            if(arr[i]*100<=s*k){
                continue;
            }
            ll q=( arr[i]*100-s*k )/k;
            if(( arr[i]*100-s*k )%k)
                q+=1;
            cnt+=q;
            s+=q;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
i
