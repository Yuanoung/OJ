//
// Created by yuanoung on 18-3-22.
//

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

#define mem(a, b) memset(a,b,sizeof(a))
#define MAXNUM 300
#define INF 0x3f3f3f3f
using namespace std;
int x[MAXNUM], y[MAXNUM], n;
double map[MAXNUM][MAXNUM];
double dis[MAXNUM];
int vis[MAXNUM];

void spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    vis[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int k = q.front();
        vis[k] = 0;
        q.pop();
        for (int j = 1; j <= n; j++)
            if (max(dis[k], map[k][j]) < dis[j]) {
                dis[j] = max(dis[k], map[k][j]);
                if (vis[j] == 0) {
                    q.push(j);
                    vis[j] = 1;
                }
            }
    }
}

int main() {
    int q = 1;
    while (~scanf("%d", &n) && n) {
        mem(map, 0);
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                map[i][j] = map[j][i] = sqrt(double(x[i] - x[j]) * (x[i] - x[j]) + double(y[i] - y[j]) * (y[i] - y[j]));
        spfa();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", q++, dis[2]);
    }
    return 0;
}
