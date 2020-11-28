#include<stdio.h>
int quickpow(int a,int b, const int c){
  int base=a%c,ans=1;
  while(b){
    if(b&1){
      ans=ans*base%c;
    }
    base=base*base%c;
    base>>=1;
  }
  return ans;
}
int main(){
  return 0;
}
