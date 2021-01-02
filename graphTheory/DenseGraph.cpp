#include<iostream>
#include<cstdio>
using namespace std;
int directed,g[105][105],n,m;
void addEdge(int v,int w){
    if(v<0||v>=n||w<0||w>=n){
        return ;
    }
    if(g[v][w])return ;
    g[v][w]=1;
    if(!directed){
        g[w][v]=1;
    }
    m++;
}
int main(){

    int k,x,y;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        addEdge(x,y);
    }
    return 0;
}

