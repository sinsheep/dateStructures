#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
int vis[10][10],dir[][2]={0,0,-1,0,1,0,0,-1,0,1};
int mat[10][10],sx,sy,tx,ty;
int pos[10][10];
struct node{
    int x,y;
    bool check(){
        if(x<0||y<0||x>9||y>9||vis[x][y]||mat[x][y]=='1'){
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
        for(int i=1;i<=4;i++){
            node tmp=top;
            tmp.x+=dir[i][0];
            tmp.y+=dir[i][1];
            if(tmp.check()){
                q.push(tmp);
                pre[tmp.x][tmp.y]=top;
                vis[tmp.x][tmp.y]=1;
                pos[tmp.x][tmp.y]=i;
            }
        }
        q.pop();
    }
    return ;
}
char getPos(int x,int y){
    int p=pos[x][y];
    if(p==1) return '^';
    if(p==2) return 'v';
    if(p==3) return '<';
    if(p==4) return '>';
    return '0';
}
void printMap(){
    char tmp[10][10];
    int qx=tx,qy=ty;
    memset(tmp,'0',sizeof(tmp));
    while(!( pre[qx][qy].x==qx&&pre[qx][qy].y==qy )){
        int prex=pre[qx][qy].x,prey=pre[qx][qy].y;
        tmp[prex][prey]=getPos(qx,qy);
        qx=prex;
        qy=prey;
    }
    tmp[sx][sy]='*';
    tmp[tx][ty]='#';
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            putchar(tmp[i][j]);
        }
        putchar('\n');
    }
}
void printPath(int x,int y){

    if(!( pre[x][y].x==x&&pre[x][y].y==y ))
    printPath(pre[x][y].x,pre[x][y].y);
    printf("(%d,%d)\n",x,y);
}
int main(){
    while(scanf("%d%d%d%d",&sx,&sy,&tx,&ty)!=EOF){
        mset(vis);
        mset(pos);
        sx--,sy--,tx--,ty--;
        pre[sx][sy]={sx,sy};
        bfs();
        printf("----\n");
        printPath(tx, ty);
        printMap();
    }
    return 0;
}
