#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, a[100005];
bool check(ll x)
{
    ll now = 0, cnt = 1;
    for (int i = 1; i <= n; i++) {
        if (now + a[i] <= x) {
            now += a[i];
        } else {
            if (a[i] > x)return false;
            cnt ++;
            now = a[i];
            if(cnt > m) return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    ll ma = 0, cnt = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        cnt += a[i];
        ma = max(ma, a[i]);
    }
    ll l = ma - 1, r = cnt + 1;
    while (l + 1 < r) {
        ll mid = (l + r) >> 1;
        // cout << mid << endl;
        if (check(mid)) {
            r = mid;
        } else
            l = mid;
    }
    cout << r << endl;
    return 0;
}
// 装果子

