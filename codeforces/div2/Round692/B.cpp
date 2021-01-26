#include<bits/stdc++.h>
#define ll long long 
#define first fi
#define second se
#define inf 0x3f3f3f3f;
#define fep(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define Rep(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
int isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
int main(){
 
    int t,n;
    cin>>t;
    // 1,5,9;
    while(t--){
        cin>>n;
        int s=1,q=1+n;
        while(!isPrime(q))q++;
        s*=q;
        q+=n;
        while(!isPrime(q))q++;
        s*=q;
        cout<<s<<endl;
    }
    return 0;
}
