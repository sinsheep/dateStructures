#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t, k, x, arr[100005]={0},cnt[100005]={0};
    cin >> t;
    while (t --) {
        cin >> n >> k;
        int ans=-1;
        memset(cnt,-1,sizeof(cnt));
        cnt[0] = 0;
        for(int i = 1; i <= n; i ++){
            cin >> x;
            arr[i] = (arr[i-1] + x) % k;
            if (cnt[arr[i]] == -1){
                cnt[arr[i]] = i;
            }else{
                ans = max(ans, i-cnt[arr[i]]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

