#include<bits/stdc++.h>
#define ll long long 
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
int t,n,ai[10100],dp[10100];
int main()
{
	while(cin>>t>>n)
	{
		mset(dp);
		for(int i=0;i<n;i++)
		{
			cin>>ai[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=t;j>=ai[i];j--)
			{
				dp[j]=max(dp[j],dp[j-ai[i]]+ai[i]);
			}
		}
		cout<<dp[t]<<endl;
	}
} 
 
