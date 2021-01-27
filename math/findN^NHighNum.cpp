#include <stdio.h>
#include <math.h>
 
int main()
{
    int i,k,t;
    double n,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&n);
        k=n*log10(n);
        a=pow(10,(n*log10(n))-k);
        printf("%d\n",(int) a);
    }
    return 0;
}

