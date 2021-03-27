#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
int n, m, arr[30005], tree[60005];
void build(int l, int r, int v){
    if(l == r){
        tree[v] = arr[l];
        return ;
    }
    int mid = (l+r) >> 1;
    build(l,mid,v<<1);
    build(mid + 1,r,v<<1|1);
    tree[v] = max(tree[v<<1],tree[v<<1|1]);
}
void update(int s,int e, int v, int idx, int val){
    if(s == e){
        tree[v] = val;
        arr[idx] =val;
        return ;
    }
    int mid = (s+e) >> 1;
    if(idx>=s&&idx<=mid)
        update(s,mid,v<<1,idx,val);
    else
        update(mid+1,e,v<<1|1,idx,val);
    tree[v] = max(tree[v<<1],tree[v<<1|1]);
}
int query(int s, int e, int v, int l, int r){
    if(r < s || e < l){
        return 0;
    } 
    if(s == e || (s >= l && e<=r)){
        return tree[v];
    }
    int mid = (s+e) >> 1;
    int ls = query(s, mid,v<<1,l,r);
    int rs = query(mid + 1, e,v<<1|1,l,r);
    return max(ls,rs);
}
int main(){
    
    while(cin >> n >> m){
        memset(tree,0,sizeof(tree));
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        build(1,n,1);
        // for(int i = 1; i <= n*2;i++){
        //     cout<<tree[i]<<endl;
        // }
        char c;int x, y;
        for(int i = 0; i < m; i++){
            cin >> c >> x >> y;
            if(c=='U'){
                update(1,n,1,x,y);
                // see("----");
            }if(c=='Q'){
                cout<<query(1,n,1,x,y)<<endl;
                // see("++++");
            }
            // else{
            //     for(int i = 1; i<=n*2;i++){
            //         cout<<tree[i]<<" ";
            //     }
            //     putchar('\n');
            // }
        }
    }
    return 0;
}
// 5 6
// 1 2 3 4 5
// U 1 99
// Q 2 5

