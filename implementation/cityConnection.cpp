//https://ac.nowcoder.com/acm/contest/11746/J
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = 1 << 30;
ll n, m, k, x, y, z, g[306][406];
int main()
{
    cin >> n >> m;
    memset(g, 0, sizeof g);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        g[x][y] = z;
        g[y][x] = z;
    }
    cin >> k;
    ll mi = inf;
    while (k--) {
        ll t, ans = 0, tmp[900], flag = 0, vis[400] = { 0 }, q;
        cin >> t;
        if (t != n) {
            for (int i = 0; i < t; i++) {
                cin >> q;
            }
            continue;
        }
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < t; i++) {
            cin >> tmp[i];
            if (vis[tmp[i]]) {
                flag = 1;
            }
            vis[tmp[i]] = 1;
            if (i == 0) {
                if (g[0][tmp[i]]) {
                    ans += g[0][tmp[i]];
                } else
                    flag = 1;
            } else {
                if (g[tmp[i - 1]][tmp[i]]) {
                    ans += g[tmp[i - 1]][tmp[i]];
                } else {
                    flag = 1;
                }
            }
        }
        if (g[0][tmp[t - 1]]) {
            ans += g[0][tmp[t - 1]];
        } else flag = 1;
        if (flag)
            continue;
        mi = min(mi, ans);
    }
    cout << (mi == inf ? -1 : mi) << endl;
    return 0;
}

