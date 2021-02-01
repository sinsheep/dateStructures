#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, arr[1000005], cnt = 0, ma = 0;
bool check(ll x){
    ll now=0, c=0;
    for(int i = 1; i <= n; i ++){
        now += arr[i];
        if (now > x){
            now = arr[i];
            c ++;
            if (c == k) return false;
        }
    }
    if (c <= k-1 && now <= x){
        return true;
    }
    return false;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        ma = max(ma, arr[i]);
        cnt += arr[i];
    }
    ll l = ma, r = cnt, ans = 0x3f3f3f3f3f3f;
    while ( l <= r ){
        ll mid = (l + r) >> 1;
        if(check(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        }else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
//划分数列
