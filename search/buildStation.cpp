#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, arr[1000005], dp[1000005];
bool judge(ll x) {

    ll now = 0;
    for(int i = 2; i <= n; i ++){
        if (arr[i] - arr[i-1] > x) {
            now += ( arr[i] - arr[i-1] ) / x;
            if(( arr[i] - arr[i-1] ) % x == 0) now --;
        }
    }
    if (now <= k) return true;
    return false;
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    ll l=0x3f3f3f3f3f3f,r=0;
    for (int i = 2; i <= n; i ++) {
        ll d = arr[i] - arr[i-1];
        if (l > d) l = d;
        if (r < d) r = d;
    }
    ll ans = 0x3f3f3f3f3f3f;
    l = (l / (k + 1));
    if (!l) l=1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if (judge(mid)) {
            ans = min(ans,mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

