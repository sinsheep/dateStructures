#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
stack<int> sk;
struct Eage {
  int to, next;
} e[MAXN];
int tot, top, cnt, n, m;
int head[MAXN], vis[MAXN], dfn[MAXN], low[MAXN];
void add(int u, int v)
{
  e[++top].to = v;
  e[top].next = head[u];
  head[u] = top;
}
void tarjan(int x)
{
  dfn[x] = low[x] = ++tot;
  sk.push(x);
  vis[x] = 1;
  for (int i = head[x]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (dfn[v] == 0) {
      tarjan(v);
      low[x] = min(low[x], low[v]);
    } else if (vis[v]) {
      low[x] = min(low[x], dfn[v]);
    }
  }
  if (low[x] == dfn[x]) {
    cnt++;
    while (1) {
      int now = sk.top();
      sk.pop();
      vis[now] = 0;
      if (now == x)
        break;
    }
  }
}
int main()
{

  while (scanf("%d%d", &n, &m), n || m) {
    while (!sk.empty())
      sk.pop();
    top = cnt = tot = 0;
    for (int i = 1; i <= n; i++)
      vis[i] = dfn[i] = low[i] = 0, head[i] = -1;
    int u, v;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &u, &v);
      add(u, v);
    }
    for (int i = 1; i <= n; i++) {
      if (dfn[i] == 0)
        tarjan(i);
    }
    cout << (cnt == 1 ? "Yes" : "No") << endl;
  }
  return 0;
}
