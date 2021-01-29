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
int flag;
void dfs(int n,int i){
   if(n==0){
        flag=1;
        return ;
   }
   if(n<0||i>n||flag)
       return ;
   // cout<<n<<" "<<i<<endl;
   dfs(n-i,i);
   dfs(n,i+10);
   
}
void solve(int n,int d){
    if(n>=d*10){
        cout<<"YES"<<endl;
        return ;
    }
    if(n%d==0){
        cout<<"YES"<<endl;
        return ;
    }
    flag=0;
    dfs(n,d);
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    
}
int main(){
    
    int q,d,t, n;
    cin>>t;
    while(t--){
        cin>>q>>d;
        for(int i=0;i<q;i++){
            cin>>n;
            solve(n,d);
        }
    }
    return 0;
}
