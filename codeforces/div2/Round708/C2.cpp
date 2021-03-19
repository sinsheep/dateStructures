#include <bits/stdc++.h>
#define ll long long
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
int k, n, t, arr[105];
int main(){
    cin >> t;
    while(t--){
        cin >> n >>k;
        int p = k - 3;
        n -= p;
        k=3;
        if(k==3){
            if(n%3==0){
                printf("%d %d %d",n/3,n/3,n/3);
            }
            else if(n%2==0){
                if(n%4==0)
                printf("%d %d %d",n/2,n/4,n/4);
                else
                printf("%d %d %d",n/2-1,n/2-1,2);
            }else{
                printf("%d %d %d",n/2,n/2,1);
            }
        }
        for(int i = 0; i < p; i++){
            printf(" 1");
        }
        putchar('\n');
    }
    return 0;
}


