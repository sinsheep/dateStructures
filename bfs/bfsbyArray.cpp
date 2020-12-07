#include<stdio.h>
#include<string.h>
int dir[][2]={{-1,0},{0,1},{1,0},{0,-1}};
char map[25][25];
int  ss[1010][3];
int main()
{
	int n,m,t,s,be=0,end=1,i,j,x,y;
	while(scanf("%d%d%d",&n,&m,&t),n||m||t)
	{
	
		memset(ss,0,sizeof(ss));
		memset(map,'*',sizeof(map));
		for(i=1;i<=m;i++)
		{
			getchar();
			for(j=1;j<=n;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')
				{
					ss[0][0]=i;
					ss[0][1]=j;
					ss[0][2]=0;
				}
			}
		}
		int p=0;	
		be=0;
		end=1;
		while(be!=end)
		{
			if(ss[be][2]==t||p==1)
			{
				break;
			}
			for(i=0;i<4;i++)
			{
				x=ss[be][0]+dir[i][0];
				y=ss[be][1]+dir[i][1];
				if(map[x][y]=='.')
				{
					ss[end][0]=x;
					ss[end][1]=y;
					ss[end][2]=ss[be][2]+1;
					end++;
					map[x][y]='*';
				} 
				if(map[x][y]=='P')
				{
					p=1;
					break;
				}
			}
			be++;
		}
		if(p==1)
		printf("YES\n");
		else
		printf("NO\n");
	}
	
	
	return 0;
}
