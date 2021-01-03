#include<stdio.h>
#include<string.h>
#define  min(a,b) a<b? (a):(b)
char str[1000005];
int alpha[26];
int check(){
    for (int i = 0; i < 26; i++) {
        if(!alpha[i])return 0;
    }
    return 1;
}
int main(){
    int n,l=0,ans=0x3f3f3f3f;
    scanf("%s",str);
    n=strlen(str);
    for(int r=0;r<n;r++){
        alpha[str[r]-'a']++;
        if(check()){
            while(alpha[str[l]-'a']>1){
                alpha[str[l++]-'a']--;
                ans=min(ans,r-l+1);
            }
        }
    }
    printf("%d\n",ans);
}
