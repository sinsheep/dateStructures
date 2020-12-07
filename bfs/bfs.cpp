#include<bits/stdc++.h>
using namespace std;
int n,m,t,dx,dy,flag;
char mp[50][50];
int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
	int x,y,step;
	bool check()
	{
		if(mp[x][y]=='*')
		return false;
		
		return true;
	}
}head,tail;

int bfs()
{
	queue<node> q;
	q.push({dx,dy,0});

	while(!q.empty())
	{
		head=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			tail=head;
			tail.x+=dir[i][0];
			tail.y+=dir[i][1];
			tail.step++;
			if(mp[tail.x][tail.y]=='P')
			return tail.step;
			if(tail.step<=t&&tail.check())
			{
				q.push(tail);
				mp[tail.x][tail.y]='*';
			}
		}
	}
	return 9999999;
}
void dfs(int x,int y,int time)
{
	if(mp[x][y]=='*'||time>t||flag==1)
	return ;
	if(mp[x][y]=='P')
	{
		flag=1;
		return ;
	}
	mp[x][y]='*';
	for(int i=0;i<4;i++)
	dfs(x+dir[i][0],y+dir[i][1],time+1);
	mp[x][y]='.';
	
}
int main()
{
	while(cin>>n>>m>>t,m&&n&&t)
	{
		memset(mp,'*',sizeof(mp));
		flag=0;
		for(int i=1;i<=m;i++)
		{
			getchar();
			for(int j=1;j<=n;j++)
			{
				cin>>mp[i][j];
				if(mp[i][j]=='S')
				{
					dx=i;
					dy=j;
				}
			}
		}
		if(bfs()<=t)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		
	}
} 
