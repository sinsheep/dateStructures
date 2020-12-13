#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct node {
    int x, y, step;
    friend bool operator<(node n1, node n2)
    {
        return n2.step < n1.step;
    }
} head, th;
int dir[][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } }, flag;
char mp[1000][1000];
int vis[1000][1000];
int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF) {
        priority_queue<node> q;
        flag = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++) {
            getchar();
            for (int j = 0; j < n; j++) {
                scanf("%c", &mp[i][j]);
                if (mp[i][j] == 'r') {
                    q.push({ i, j, 0 });
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            if (flag)
                break;
            head = q.top();
            q.pop();
            for (int i = 0; i < 4; i++) {
                th = head;
                th.x += dir[i][0];
                th.y += dir[i][1];
                th.step++;
                if (th.x < m && th.y < n && th.x >= 0 && th.y >= 0 && mp[th.x][th.y] != '#' && !vis[th.x][th.y]) {
                    if (mp[th.x][th.y] == '.') {
                        vis[th.x][th.y] = 1;
                        q.push(th);
                    }
                    if (mp[th.x][th.y] == 'x') {
                        vis[th.x][th.y] = 1;
                        th.step++;
                        q.push(th);
                    }
                    if (mp[th.x][th.y] == 'a') {
                        vis[th.x][th.y] = 1;
                        q.push(th);
                        printf("%d\n", th.step);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (!flag)
            printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}
