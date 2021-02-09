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
    int t, n, m;
    string str;
    cin >> t;
    while(t--){
        cin >> str;
        for( int i = 0; i < str.length(); i ++ ){
            if(i%2==0){
                if(str[i]=='a')putchar('b');
                else putchar('a');
            }else{
                if(str[i]=='z')putchar('y');
                else putchar('z');
            }
        }
        putchar('\n');
    }
    return 0;
}
