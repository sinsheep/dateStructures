#include <bits/stdc++.h>
#define ll long long
using namespace std;
int tree[200005], arr[100005], n, m, add[200005];
void build(int l, int r, int node){
    if(l == r){
        tree[node] = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, node << 1);
    build(mid + 1, r, node << 1 | 1);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}
int query(int l, int r, int node,int s,int e){
    if((l>=s && r<=e)){
        return tree[node];
    }
    int mid = (l + r)>>1;
    if(add[node]){
        tree[node<<1] += add[node]*(mid-l+1);
        tree[node<<1|1] += add[node]*(r - mid);
        add[node << 1] += add[node];
        add[node << 1|1] += add[node];
        add[node] = 0;
    }
    int sum = 0;
    if(s<=mid){
        sum +=query(l, mid, node<<1,s,e);
    }
    if(e>mid){
        sum += query(mid + 1, r, node<<1|1,s,e);
    }
    return sum;
}
void update(int l, int r, int node, int x,int s, int e){
    if((l>=s && r<=e)){
        tree[node] += x*(r-l+1);
        add[node] += x;
        return ;
    }
    int  mid = (l + r) >> 1;
    if(add[node]){
        tree[node<<1] += add[node]*(mid-l+1);
        tree[node<<1|1] += add[node]*(r - mid);
        add[node << 1] += add[node];
        add[node << 1|1] += add[node];
        add[node] = 0;
    }
    if(s<=mid){
        update(l, mid, node<<1, x, s, e);
    }
    if(e>mid){
        update(mid + 1, r, node<<1|1, x, s, e);
    }
    tree[node] = tree[node<<1] + tree[node<<1|1];
}
int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1,n,1);
    int t, l, r, x;
    for(int i = 0; i < m; i++){
        cin >> t;
        if(t==2){
            cin >> l >> r;
            cout<<query(1,n,1,l,r)<<endl;
            // cout<<"+++"<<endl;
        }else{
            cin >> l >> r >> x;
            update(1,n,1,x,l,r);
            // cout<<"---"<<endl;
        }
    }
    return 0;
}
