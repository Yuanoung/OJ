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
#define MAXNUM 300
using namespace std;
int x[MAXNUM], y[MAXNUM], n;
double map[MAXNUM][MAXNUM];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = min(map[i][j], max(map[i][k], map[k][j])); //许多通路中最长边中的最小边
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
        floyd();
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", q++, map[1][2]);
    }
    return 0;
}

