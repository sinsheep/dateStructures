#include<bits/stdc++.h>
using namespace std;
const int MAXN=500010;
int a[MAXN], b[MAXN], c[MAXN];
struct node{
    int x,val,from;
};
bool operator <(node a,node b){
    return a.val>b.val;
}
inline int calc(int n,int x){
    return a[n]*x*x+b[n]*x+c[n];
}
priority_queue<node> q;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i]>>c[i];
        q.push(node{1,calc(i,1),i});
    }
    for(int i=0;i<m;i++){
        node tmp=q.top();
        cout<<tmp.val<<" ";
        q.pop();
        q.push(node{tmp.x+1,calc(tmp.from,tmp.x+1),tmp.from});
    }
    return 0;
}

