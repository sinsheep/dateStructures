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
int main(){
 
    int t,n;
    string a,b;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>a;
        int last=-1;
        for(int i=0;i<n;i++){
            if(last!=a[i]-'0'+1){
                putchar('1');
                last=a[i]-'0'+1;
            }else{
                last=a[i]-'0';
                putchar('0');
            }
        }
        putchar('\n');
    }
    return 0;
}
 
