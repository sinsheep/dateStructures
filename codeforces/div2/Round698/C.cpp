#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define Fep(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define Rep(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int, int> pii;
ll d[200005];
bool cmp(ll a,ll b){
    return a>b;
}
int main()
{
    ll n, t, m;
    cin >> t;
    while (t--) {
        cin >> n;
        n = 2 * n;
        m = n;
        for (ll i = 1; i <= n; i++) {
            cin >> d[i];
        }
        ll f = 0, s = 0;
        sort(d+1,d+n+1,cmp);
        for (ll i = 1; i <= n; i += 2) {
            if ( (d[i] - s <= 0) ||(d[i] - s) % m|| d[i] != d[i + 1] || d[i - 1] == d[i]) {
                f = 1;
                break;
            }
            s+=(d[i]-s)*2/m;
            m -= 2;
        }
        cout << (f ? "NO" : "YES") << endl;
    }
    return 0;
}
