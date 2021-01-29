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
    
    int m,n,t, arr[200];
    cin>>t;
    while(t--){
        int s=0;
        map<int,int> q;
        cin>>n;
        for(int i=0;i<n;i++){
             cin>>arr[i];
             q[arr[i]]++;
             s=max(s,q[arr[i]]);
        }
        cout<<s<<endl;
    }
    return 0;
}

