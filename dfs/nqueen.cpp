#include <stdio.h>
int map[15][15]={0},count=0,n;
int check(int x,int y){
	for(int i=y;i>=0;i--){
		if(map[x][i]==1)
		return 0;
	}
	for(int i=x;i>=0;i--){
		if(map[i][y]==1)
		return 0;
	}
	for(int i=y,t=0;i<n;t++,i++){
		if(x-t<0)
		break;
		if(map[x-t][i]==1)
		return 0;
	}
	for(int i=y,t=0;i>=0;t++,i--){
		if(x-t<0)
		break;
		if(map[x-t][i]==1)
		return 0;
	}
	return 1;
	
}
void dfs(int row)
{
	if(row==n){
		printf("case%d:\n",++count);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			printf("%d%c",map[i][j],j==n-1?'\n':' ');
			
		}
		return ;
	}
	for(int j=0;j<n;j++){
		if(check(row,j))
		{
			map[row][j]=1;
			dfs(row+1);
			map[row][j]=0;
		}
	}
}
int main(){
	int time=0;
	while(scanf("%d",&n),n!=-1){
		if(time++!=0)
		putchar('\n');
		count=0;
		dfs(0);
		printf("There are %d kinds of\n",count);
	}
	return 0;
}
