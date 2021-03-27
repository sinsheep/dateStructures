#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
int h, w, n, vol[50005], t;
void build(int l,int r,int v){
    if(l == r){
        vol[v]=w;
        return ;
    }
    int mid = (l + r) >> 1;
    vol[v] = w;
    build(l,mid,v << 1);
    build(mid + 1, r, v << 1 | 1);
}
int update(int l, int r,int v,int wi){
    if(l == r){
        vol[v] -= wi;
        return l;
    }
    int mid = (l + r) >> 1, ans;
    if(wi <= vol[v<<1])
        ans = update(l,mid,v << 1,wi);
    else
        ans = update(mid + 1,r,v << 1 | 1,wi);
    vol[v] = max(vol[v<<1], vol[v <<1|1]);
    return ans;
}
int main(){
    
    cin >> h >> w >> n;
    build(1, h, 1);
    for(int i = 0; i < n; i++){
        cin >> t;
        if(t>vol[1])
            cout<<"-1"<<endl;
        else 
            cout<<update(1,h,1,t)<<endl;
    }
    return 0;
}
