#include<stdio.h>
int a[10][4]={{0},{1},{6,2,4,8},{1,3,9,7},{6,4},{5},{6},{1,7,9,3},{6,8,4,2},{1,9}};
int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		if(n%10==0||n%10==1||n%10==5||n%10==6)
		printf("%d\n",a[n%10][0]);
		if(n%10==4||n%10==9)
		printf("%d\n",a[n%10][n%2]);
	    if(n%10==2||n%10==3||n%10==7||n%10==8)
	    printf("%d\n",a[n%10][n%4]);
	}
	return 0;
}
