#include <bits/stdc++.h>
#define ll long long
#define mset(a) memset(a,0,sizeof(a))
using namespace std;
int m, n, t, arr[105];
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr,arr+n);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(i>0&&arr[i] == arr[i-1]){
                q.push(arr[i]);
                continue;
            }
            if(i)putchar(' ');
            printf("%d",arr[i]);
        }
        while(!q.empty()){
            printf(" %d",q.front());
            q.pop();
        }
        putchar('\n');
    }
    return 0;
}

