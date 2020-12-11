#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return (*(int*)a-*(int *)b);
}
int a[20010],b[20010];
int main()
{
	int m,n,i,j,sum,t,su;
	while(scanf("%d%d",&m,&n),m||n)
	{
		sum=0;
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		qsort(a,m,sizeof(a[0]),cmp);
		qsort(b,n,sizeof(b[0]),cmp);
		t=0;
		su=0;
		for(i=0;i<m;i++)
		{
			while(t<n)
			{
				if(a[i]<=b[t])
				{
					
					sum++;
					su+=b[t];
					t++;
					break;
				}
				t++;
			}
		}
		if(sum!=m)
		printf("Loowater is doomed!\n");
		else
		printf("%d\n",su);
	}
	
}
