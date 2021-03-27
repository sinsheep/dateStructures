#include<bits/stdc++.h>
#define ll long long 
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int,int> pii;
int t, n, arr[50005],tree[100005];   
void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return ;
    }
    int mid = (l + r) >> 1, ln = node * 2 + 1, rn  = node * 2 + 2;
    build(ln,l,mid);
    build(rn,mid+1,r);
    tree[node] = tree[ln] + tree[rn];
}
void update(int start,int end, int node,int idx, int val){
    if(start == end){
        tree[node] = val;
        arr[start] = val;
        // cout << end << "---"<< arr[start]<<endl;
        return ;
    }
    int ln = node * 2 + 1;
    int rn = node * 2 + 2;
    int mid = ( start + end ) >> 1;
    if(idx>=start && idx <= mid){
        update(start,mid,ln,idx,val);
    }else {
        update(mid + 1,end, rn,idx, val);
    }
    tree[node] = tree[ln] + tree[rn];
}
int query(int start,int end, int node,int l, int r){
    if(l > end || r <  start) return 0;
    if(start == end) return tree[node];

    if(start>=l && end<=r) return tree[node];
    int mid = (start + end) >> 1;
    int ln = node * 2 + 1;
    int rn = node * 2 + 2;
    int ls = query(start,mid,ln,l,r);
    int rs = query(mid + 1,end,rn,l,r);
    return ls + rs;
}
int main(){
    cin >> t;
    for(int j = 1; j <= t; j ++){
        memset(tree,0,sizeof(tree));
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arr[i];
        build(0,0,n-1);
        // for(int i = 0; i < n * 2; i++){
        //     cout<<tree[i]<<" ";
        // }
        string str;
        printf("Case %d:\n",j);
        while(cin>>str,str!="End"){
            int x, y;
            cin >> x >> y;
            x--;
            if(str == "Query"){
                y--;
                cout<<query(0,n-1,0,x,y )<< endl;
            }else if(str == "Add"){
                update(0,n-1,0,x,arr[x] + y);
            }else if(str == "Sub"){
                update(0,n-1,0,x,arr[x] - y);
            }

        }
    }
    return 0;
}
