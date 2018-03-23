//
// Created by yuanoung on 3/23/18.
//
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MaxN = 10007;
vector<int> a[MaxN];
vector<int> ask[MaxN];
int f[MaxN], vis[MaxN], ans, n, t, x, y, isf[MaxN];

void tarjan(int);

int findroot(int);

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(f, -1, sizeof(f));
        memset(vis, 0, sizeof(vis));
        memset(isf, 0x3f, sizeof(isf));
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            ask[i].clear();
        }
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            a[x].push_back(y);
            isf[y] = 0;
        }
        scanf("%d%d", &x, &y);
        ask[x].push_back(y);
        ask[y].push_back(x);
        for (int i = 1; i <= n; i++) {
            if (isf[i]) {
                tarjan(i);
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void tarjan(int x) {
    for (int i = 0; i < a[x].size(); i++) {
        tarjan(a[x][i]);
        f[a[x][i]] = x;
    }
    vis[x] = 1;
    for (int i = 0; i < ask[x].size(); i++)
        if (vis[ask[x][i]]) {
            ans = findroot(ask[x][i]);
            return;
        }
}

int findroot(int x) {
    return f[x] == -1 ? x : f[x] = findroot(f[x]);
}

