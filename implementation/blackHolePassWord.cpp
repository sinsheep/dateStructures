#include <bits/stdc++.h>
#define ll long long
using namespace std;
string str;
int  n, num[50], a;
char  alpha[50];
void pri(int x){

    if (isupper(alpha[x])) {
        alpha[x] = alpha[x] + num[x];
        putchar(alpha[x] > 'Z' ? 'a' + alpha[x]-'Z': alpha[x]);
    } else{
        alpha[x] = alpha[x] -'a' + num[x] + 1;
        putchar(alpha[x] > 26 ? 'A' + alpha[x] - 26: 'a' + alpha[x] - 1);
    }
}
// Zzc9Ltw9OD4yR640263W7G8G30HW9C71
int main(){
    cin >> str;
    for (int i = 0; i < 32; i ++){
        if (isdigit(str[i])) {
            num[n++] = str[i]-'0';
        } else {
            alpha[a++] = str[i];
        }
    }
    for (int i = 0; i <16; i +=4) {
        pri(i+3);
        pri(i+2);
        pri(i+1);
        pri(i);
    }
    return 0;
}

//url:=https://ac.nowcoder.com/acm/contest/11746/K
