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
    int t;
    cin>>t;
    while(t--){
        ll ai[200005]={},bi[200005]={},ci[200005]={},n;
        cin>>n;
        ll m=0;
        for(int i=0;i<n;i++)cin>>ai[i];
        for(int i=0;i<n;i++)cin>>bi[i];
        for(int i=0;i<n;i++)cin>>ci[i];
        ll cnt=0;
        for(int i=1;i<n;i++){
            if(ci[i]==bi[i])cnt=0;
            else if(ci[i]<bi[i]) swap(ci[i],bi[i]);
            if(cnt<ci[i]+ci[i]-bi[i]-bi[i]) cnt=1+ai[i]+ci[i]-bi[i];
            else cnt+=1+ai[i]+bi[i]-ci[i];
            if(cnt>m) m=cnt;
        }
        cout<<m<<endl;
    }
}


