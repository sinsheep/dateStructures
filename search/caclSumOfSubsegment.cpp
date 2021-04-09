#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
double arr[100005], pre[100005];
int main(){
    
    int n, L;
    cin >> n >> L;
    double esp = 1e-6;
    double l = 0, r = 2000.0;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    while(r-l>esp){
        double mid = (l + r)/2;
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i-1]+arr[i]-mid;
        }
        double mi = 0x3f3f3f3f,ma=-0x3f3f3f3f;
        for(int i = L; i<=n;i++){
            mi = min(mi,pre[i-L]);
            ma = max(ma,pre[i]-mi);
        }
        if(ma>=0)
            l=mid;
        else
            r=mid;
        // cout<<l<<" "<<r<<endl;
    }
    printf("%d\n",int(r*1000));
    int i = INT_MAX;
    return 0;
}
