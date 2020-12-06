//problemLink:http://www.tzcoder.cn/acmhome/problemdetail.do?method=showdetail&id=1005
#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
int flag,m,n,t;
int dir[][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(int x,int y,int step){
    /* printf("%d %d %d\n",x,y,step); */
    if(x<0||x>=m||y<0||y>=n||flag){
        return ;
    }
    if(arr[x][y]=='P'){
        flag=1;
        return ;
    }
    if(step==0||arr[x][y]=='*'){
        return ;
    }
    arr[x][y]='*';
    for(int i=0;i<4;i++){
        dfs(x+dir[i][0],y+dir[i][1],step-1);
    }
    arr[x][y]='.';
}
int main()
{    
    while(scanf("%d%d%d",&n,&m,&t),m||n||t){
        int dx,dy;
        for(int i=0;i<m;i++){
            getchar();
            for(int j=0;j<n;j++){
                scanf("%c",&arr[i][j]);
                if(arr[i][j]=='S'){
                    dx=i;
                    dy=j;
                }
            }
        }
        flag=0;
        dfs(dx,dy,t);
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}
