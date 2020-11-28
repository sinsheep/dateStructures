#include<stdio.h>
#define MAXL 3000005
int len[MAXL];
char str[MAXL],s[MAXL];
void init(){
  int k=0;
  str[k++]='^';
  for (int i = 0; s[i]!='\0'; i++) {
    str[k++]='#';
    str[k++]=s[i];
  }
  str[k]='%';
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%s",s);
  }
}
