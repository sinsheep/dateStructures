#include<bits/stdc++.h>
#define see(x) cout<<(x)<<endl;
using namespace std;
void getNext(char *s,int *next){
    int l = strlen(s);
    int j = 0, i = 1;
    next[0] = -1;
    while(i < l){
        if(j==-1 || s[i] == s[j]){
            i++;j++;
            next[i] = j;
        }else{
            j = next[j];
        }
    }
    for(int k = 0; k < l;k++){
        cout<<next[k]<<" ";
    }
    putchar('\n');
}
int IndexKmp(char *s1,char *s2 ,int next[]){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int i = 0, j=0;
    while(i < l1 && j<l2){
        if(j==-1||s1[i]==s2[j]){
            i++;
            j++;
        }else{
            j = next[j];
        }
    }
    if(j==l2){
        return i - j;
    }
    return -1;
}
int main(){
    char s1[] ="sdkjaglkjdsaklgjsdklajabaabcaba";
    char s2[] = "abaabcaba";
    int next[1000];
    getNext(s2,next);
    cout<<IndexKmp(s1, s2, next);
    return 0;
}
