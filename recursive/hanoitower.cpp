#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int n;
void dfs(int n,char a,char b,char c){
  if(n==1){
    printf("%d %c %c\n",n,a,c);
    return ;
  }else{
    dfs(n-1,a,c,b);
    printf("%d %c %c\n",n,a,c);
    dfs(n-1,b,a,c);
  }
}
void solve(){
  cin>>n;
  dfs(n,'A','C','B');
}
int main()
{
  solve();
  return 0;
}


