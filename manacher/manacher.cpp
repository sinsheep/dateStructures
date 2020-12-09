#include<stdio.h>
#define max(a,b) (a)>(b)? (a):(b)
#define min(a,b) (a)>(b)? (b):(a)
#define MAXL 3000005
int len[MAXL],l,m=0;
char str[MAXL],s[MAXL];
void init(){
  int k=0;
  str[k++]='^';
  for (int i = 0; s[i]!='\0'; i++) {
    str[k++]='#';
    str[k++]=s[i];
  }
  str[k]='#';
  str[k+1]='%';
  l=k;
}
void manacher(){
    int mx=0,id;
    for(int i=0;i<l;i++){
        if(i<mx){
            len[i]=min(len[2*id-i],mx-i);
        }else{
            len[i]=1;
        }
        while(str[i+len[i]]==str[i-len[i]])
            len[i]++;
        if(i+len[i]>mx){
            mx=i+len[i];
            id=i;
        }
        m=max(m,len[i]-1);
    }
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%s",s);
    init();
    m=0;
    manacher();
    printf("%d\n",m);
  }
}
