//
// Created by yuanoung on 18-3-22.
//

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>

#define INF 0x3f3f3f3f
using namespace std;
struct node {
    double x, y;
};
node nd[205];

struct EDGE {
    int u, v;
    double dist;
};
EDGE edge[21000];

bool cmp(EDGE a, EDGE b) {
    return a.dist < b.dist;
}

double g[205][205];

int vis[205], f[205];
int n;

int getFather(int x) {
    return x == f[x] ? x : f[x] = getFather(f[x]);
}

bool Union(int a, int b) {
    int fa = getFather(a), fb = getFather(b);
    if (fa != fb) {
        f[fa] = fb;
        return true;
    }
    return false;
}

double dd;

bool dfs(int cur, double ddd) {
    vis[cur] = 1;
    if (cur == 2) {
        dd = ddd;
        return true;
    }
    for (int i = 1; i <= n; ++i)
        if (g[cur][i] != INF && !vis[i]) {
            if (ddd < g[cur][i]) {
                if (dfs(i, g[cur][i])) return true;
            } else if (dfs(i, ddd)) return true;
        }
    return false;
}

int main() {
    int cnt = 0;
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = INF;
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            double u, v;
            cin >> nd[i].x >> nd[i].y;
            for (int j = 1; j < i; ++j) {
                u = nd[i].x - nd[j].x;
                v = nd[i].y - nd[j].y;
                edge[count].u = i;
                edge[count].v = j;
                edge[count++].dist = sqrt(u * u + v * v);
            }
        }
        sort(edge, edge + count, cmp);
        for (int i = 1; i <= n; ++i)
            f[i] = i;
        for (int i = 0; i < count; ++i) {
            int u, v;
            if (Union(u = edge[i].u, v = edge[i].v))
                g[u][v] = g[v][u] = edge[i].dist;
        }
        memset(vis, 0, sizeof(vis));
        dfs(1, 0.0);
        cout << "Scenario #" << ++cnt << endl << "Frog Distance = ";
        cout << fixed << setprecision(3) << dd << endl;
        cout << endl;
    }
    return 0;
}