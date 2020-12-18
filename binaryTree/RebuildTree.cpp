#include<stdio.h>
#include<string.h>
void build(int n,char *pre,char *mid,char *post){
    if(n<=0)return ;
    int p=strchr(mid, pre[0])-mid;
    build(p,pre+1,mid,post);
    build(n-p-1,pre+p+1,mid+p+1,post+p);
    post[n-1]=pre[0];
}
int main(){
    char pre[100]="DBACEGF",mid[100]="ABCDEFG",post[100];
    int n=strlen(pre);
    printf("%d",n);
    build(n,pre,mid,post);
    post[n]='\0';
    puts(post);
    return 0;
}
