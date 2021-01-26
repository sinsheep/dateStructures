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
const int MAXN=200005;
int a[MAXN],b[MAXN],c[MAXN];
int main(){
    int T,n; 
    cin>>T;
    while(T--){
        cin>>n;
        Fep(i,1,n)cin>>a[i],b[i]=c[i]=0;
        b[0]=0;
        c[n+1]=0;
        Fep(i,1,n)b[i]=a[i]>=b[i-1]&&b[i-1]!=-1?a[i]-b[i-1]:-1;
        Rep(i,n,1)c[i]=a[i]>=c[i+1]&&c[i+1]!=-1?a[i]-c[i+1]:-1;
        if(!b[n]){
            cout<<"YES\n";
            continue;
        }
        int flag=0;
        Fep(i,1,n-1){
            if(b[i-1]!=-1&&c[i+2]!=-1&&a[i+1]>=b[i-1]&&a[i]>=c[i+2]&&a[i]-c[i+2]==a[i+1]-b[i-1]){
                cout<<"YES\n";
                flag=1;
                break;
            }
        }
        if(!flag)cout<<"NO\n";
    }
    return 0;
}
