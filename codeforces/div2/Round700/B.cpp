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
struct node {
    ll a, b;
}mon[100005];
bool cmp(node a, node b){
    return a.a < b.a;
}
int main(){
    ll t, n, m, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b >>n;
        for(int i = 0; i < n;i ++){
            cin >> mon[i].a;
        }
        for(int i = 0; i < n;i ++){
            cin >> mon[i].b;
        }
        sort(mon,mon+n,cmp);
        int flag=1;
        for (int i = 0; i < n; i ++){
            while(mon[i].b>0&&b>0){
                b-=mon[i].a;
                mon[i].b-=a;
            }
            if(mon[i].b>0){
                flag=0;
                break;
            }
        }
        cout << (flag ? "YES":"NO") <<endl;
    }

    return 0;
}

