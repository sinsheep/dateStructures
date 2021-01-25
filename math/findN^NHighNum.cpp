#include <stdio.h>
#include <math.h>
 
int main()
{
    int i,k;
    double n,a;
    while(scanf("%lf",&n)!=EOF)
    {
        k=n*log10(n);
        a=pow(10,(n*log10(n))-k);
        printf("%d\n",(int) a);
    }
    return 0;
}

