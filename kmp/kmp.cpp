#include<bits/stdc++.h>
int kmp_search(char p1[],char p2[],int next[]){
  int i = 0;
  int j = 0;
  int ilen = strlen(p1);
  int jlen = strlen(p2);
  while(i<ilen&&j < jlen){
    if(j == -1||p1[i]==p2[j]){
      i++;
      j++;
    }else{
      j=next[j];
    }
  }
  if(j==jlen){
    return i-j;
  }else{
    return -1;
  }
}
void creat_next(char p[],int next[]){
  next[0]=-1;
  next[1]=0;
  int k=0;
  for(int i=1;p[i]!='\0';i++){
    if(p[i]==p[k]){
      k++;
    }
    else{
      k=0;
    }
    next[i+1]=k;
  }
  for (int i = 0; p[i]!='\0'; i++) {
    printf("%d ",next[i]) ;
  }
}
int main(){
  char p1[]="ababababca";
  char p2[]="abababc";
  int next[100];
  creat_next(p2,next);
  putchar('\n');
  std::cout<<kmp_search(p1, p2, next)<<std::endl;
}
