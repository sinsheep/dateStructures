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
        int q=n/2020,s=n%2020;
        // cout<<q<<" "<<s<<endl;
        if(s<=q){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
