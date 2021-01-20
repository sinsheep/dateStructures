#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define inf 0x3f3f3f3f;
#define fep(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define rep(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define see(x) cout << (x) << '\n'
typedef double db;
using namespace std;
typedef pair<int, int> pii;
int m, n, t, a[2005], ok;
map<int, int> cnt;
void burn(int x){
    if (--cnt[x] == 0)
        cnt.erase(x);
}
int main(){

    cin >> t;
    while (t--) {
        cin >> n;
        ok = 0;
        fep(i, 1, 2 * n) cin >> a[i];
        sort(a + 1, a + 2 * n + 1);
        fep(i, 1, 2 * n - 1)
        {
            cnt = map<int, int>();
            fep(j, 1, 2 * n) cnt[a[j]]++;
            int ma = a[2 * n], y = a[i], flag = 1;
            burn(a[2 * n]);
            burn(a[i]);
            m = 2;
            vector<pii> h;
            h.push_back({ ma, y });
            while (m < 2 * n) {
                auto end = cnt.rbegin();
                int x = (*end).fi;
                burn(x);
                if (!cnt.count(ma - x)) {
                    flag = 0;
                    break;
                }
                h.push_back({ x, ma - x });
                burn(ma - x);
                ma = x;
                m += 2;
            }
            if (!flag)
                continue;
            cout << "YES" << endl;
            cout << a[i] + a[2 * n] << endl;
            for (auto it : h) {
                cout << it.fi << " " << it.se << endl;
            }
            ok=1;
        }
        if(!ok)
        cout << "NO" << endl;
    }
    return 0;
}
//url:https://codeforces.com/contest/1474/problem/C
