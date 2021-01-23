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
int fa[1005],n,cnt;
void init1(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(x!=fa[x]){
        fa[x]=find(fa[x]);
    }
    return fa[x];
}
void join(int x,int y){
    int x_r=find(x);
    int y_r=find(y);
    if(x_r!=y_r){
        fa[x_r]=y_r;
    }
}
int main(){
    int m, x, y;
    while(cin >> n >> m){
        if(m==0&&n==0)break;
        cnt=0;
        init1();
        for(int i=0;i<m;i++){
            cin>>x>>y;
            join(x,y);
        }
        for(int i=1;i<=n;i++){
            if(i==fa[i])cnt++;
        }
        if(cnt==1&&m==n-1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
//url:http://acm.zzu.edu.cn/problem.php?cid=1049&pid=0
