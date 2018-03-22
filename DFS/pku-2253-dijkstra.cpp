//
// Created by yuanoung on 18-3-22.
//

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

#define mem(a, b) memset(a,b,sizeof(a))
#define maxnum 300
#define inf 0x3f3f3f3f
using namespace std;
int x[maxnum], y[maxnum], n;
double map[maxnum][maxnum];
double dis[maxnum];
int vis[maxnum];

void dj(int s) {
    mem(vis, 0);
    for (int i = 1; i <= n; i++)
        dis[i] = inf;//这里最好别用memset
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        int minn = inf, k;
        for (int j = 1; j <= n; j++)
            if (vis[j] == 0 && dis[j] < minn) {
                k = j;
                minn = dis[j];
            }
        vis[k] = 1;
        for (int j = 1; j <= n; j++)
            dis[j] = min(dis[j], max(dis[k], map[k][j]));//dis[j]为从一号石头到第j号石头所有通路中最长边中的最小边
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
        dj(1);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", q++, dis[2]);
    }
    return 0;
}
