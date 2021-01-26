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
    
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<string> a(n), b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=(a[i][j]-'0')^(b[i][j]-'0');
        bool flag=true;
        for(int i=1;i<n;i++){
            char tmp=a[i][0]^a[i-1][0];
            for(int j=0;j<n;j++){
                if((a[i][j]^a[i-1][j])!=tmp){
                    flag=0;
                    break;
                }
                if(!flag)break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
    return 0;
}
