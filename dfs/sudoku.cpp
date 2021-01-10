#include<stdio.h>
#include<cstring>
#include<iostream>
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
char mat[10][10];
int row[10][10],col[10][10],n,matrix[10][10],num[105],s,flag;
void dfs(int now){
    if(flag)return;
    if(now==s){
        flag=1;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                putchar(mat[i][j]);
            }
            putchar('\n');
        }
        return ;
    }
    int dx=num[now]/9;
    int dy=num[now]%9;
    for(int i=1;i<10;i++){
        if(matrix[3*(dx/3)+dy/3][i]==0&&row[dx][i]==0&&col[dy][i]==0){
            matrix[3*(dx/3)+dy/3][i]=1;
            row[dx][i]=1;
            col[dy][i]=1;
            mat[dx][dy]=i+'0';
            dfs(now+1);
            mat[dx][dy]='*';
            matrix[3*(dx/3)+dy/3][i]=0;
            row[dx][i]=0;
            col[dy][i]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int p=0;p<n;p++){
        mset(row);mset(col);mset(matrix);
        s=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cin>>mat[i][j];
                if(isdigit(mat[i][j])){
                    row[i][mat[i][j]-'0']=1;
                    col[j][mat[i][j]-'0']=1;
                    matrix[3*(i/3)+j/3][mat[i][j]-'0']=1;
                }else{
                    num[s++]=i*9+j;
                }
            }
        }
        flag=0;
        dfs(0);
        putchar('\n');
    }
    return 0;
}
