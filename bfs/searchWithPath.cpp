#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
int vis[10][10],dir[][2]={1,0,0,1,0,-1,-1,0};
int mat[10][10],sx,sy,tx,ty;
struct node{
    int x,y;
    bool check(){
        if(x<0||y<0||x>9||y>9||vis[x][y]){
            return false;
        }
        return true;
    }
};
node pre[10][10];
void bfs(){
    queue<node> q;
    q.push({sx,sy});
    vis[sx][sy]=1;
    while(!q.empty()){
        node top=q.front();
        if(top.x==tx&&top.y==ty){
            return ;
        }
        // printf("%d %d\n",top.x,top.y);
        for(int i=0;i<4;i++){
            node tmp=top;
            tmp.x+=dir[i][0];
            tmp.y+=dir[i][1];
            if(tmp.check()){
                q.push(tmp);
                pre[tmp.x][tmp.y]=top;
                vis[tmp.x][tmp.y]=1;
            }
        }
        q.pop();
    }
    return ;
}
void printPath(int x,int y){

    if(!( pre[x][y].x==x&&pre[x][y].y==y ))
    printPath(pre[x][y].x,pre[x][y].y);
    printf("(%d,%d)",x,y);
}
int main(){
    while(scanf("%d%d%d%d",&sx,&sy,&tx,&ty)!=EOF){
        mset(vis);
        pre[sx][sy]={sx,sy};
        bfs();
        printf("----\n");
        printPath(tx, ty);
    }
    return 0;
}
