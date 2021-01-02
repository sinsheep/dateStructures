#include<iostream>
#include<vector>
using namespace std;
int m,n,directed;
vector<int> g[105];
bool hasEdge(int v,int w){
    for(int i=0;i<g[v].size();i++){
        if(g[v].at(i)==w)return true;
    }
    return false;
}
void addEdge(int v,int w){
    if(v<0||v>=n||w<0||w>=n){
        return ;
    }
    g[v].push_back(w);
    if(v!=w&&!directed){
        g[w].push_back(v);
    }
    m++;
}
int main(){
    int x,y,k;
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        if(!hasEdge(x,y)){
           addEdge(x, y);
        }
    }
    return 0;
}
