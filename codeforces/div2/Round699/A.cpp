#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define Rep(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int, int> pii;
const int N = 100005;
int t, n, m, a[N],b[N], c[N], d[N];
int main(){

    cin >> t;
    while (t--) {
        int s=0, f=0;
        cin >> n >> m;
        queue<int> q, o;
        queue<int> que[100005];
        memset(d, -1, sizeof d);
        for (int i = 0; i < n; i ++) {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i < n; i ++) {
            scanf("%d",&b[i]);
            if(a[i]!=b[i]) {
                que[b[i]].push(i);
            }
            d[b[i]]=i;
        }
        // cout<<"----"<<d[1]<<"----"<<d[0]<<endl;
        int lasti=-1;
        for (int i = 0; i < m; i ++) {
            scanf("%d",&c[i]);
            if(d[c[i]]!=-1||!que[c[i]].empty()){
                lasti=i;
            }
        }
        for (int i = 0; i < m; i ++) {
            if(!que[c[i]].empty()){
                s++;
                q.push(que[c[i]].front());
                que[c[i]].pop();
                if(f>0)
                f--;
            }else if(d[c[i]]!=-1){
                s++;
                q.push(d[c[i]]);
                if(f>0)
                f--;
            }else if(i<lasti){
                s++;
                q.push(lasti);
                f++;
            }
        }
        if(s==m &&f==0){
            cout<<"YES"<<endl;
            int p=0;
            while(!q.empty()){
                if(p++)putchar(' ');
                cout<<q.front()+1;
                q.pop();
            }
            putchar('\n');
        }else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
