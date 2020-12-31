#include <bits/stdc++.h>
using namespace std;
int n,vis[26]={0},s;
char str[1000],tmp[1000];
void dfs(int k){
  if(k==n){
    s++;
    for(int i=0;i<n;i++)printf("%c",tmp[i]);
    printf("\n");
    return ;
  }
  for(int i=0;i<26;i++){
      if(vis[i]){
          vis[i]--;
          tmp[k]=i+'a';
          dfs(k+1);
          vis[i]++;
      }
  }
}
void solve(){
  cin>>n;
  cin>>str;
  for(int i=0;i<n;i++){
      vis[str[i]-'a']++;
  }
  dfs(0);
  cout<<s<<endl;
}
int main()
{
  solve();
  return 0;
}
