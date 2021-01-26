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
const int MAXN=2e5+7;
int t, n, m, V[MAXN],tmp;
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<ll> a,b;
        for(int i=0;i<n;i++)cin>>V[i];
        for(int i=0;i<n;i++){
            cin>>tmp;
            if(tmp&1)a.push_back(V[i]);
            else b.push_back(V[i]);
        }
        // cout<<a.size()<<" "<<b.size()<<endl;
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        for(int i=1;i<a.size();i++)a[i]+=a[i-1];
        for(int i=1;i<b.size();i++)b[i]+=b[i-1];
        int ans=INT_MAX;
        auto iter =lower_bound(a.begin(), a.end(), m);
        if(iter!=a.end())ans=min(ans,(int)(iter-a.begin()+1));
        iter = lower_bound(b.begin(), b.end(), m);
        if(iter!=b.end())ans=min(ans,(int)(iter-b.begin()+1)*2);
        for(int i=0;i<a.size();i++){
            iter = lower_bound(b.begin(),b.end(),m-a[i]);
            if(iter!=b.end())ans=min(ans,i+1+(int)(iter-b.begin()+1)*2);
        }
        for(int i=0;i<b.size();i++){
            iter = lower_bound(a.begin(),a.end(),m-b[i]);
            if(iter!=a.end())ans=min(ans,( i+1 )*2+(int)(iter-a.begin()+1));
        }
        cout<<(ans==INT_MAX?-1:ans)<<endl;
    }
    return 0;
}

