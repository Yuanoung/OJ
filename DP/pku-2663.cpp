//
// Created by yuanoung on 3/30/18.
//
// f[i][0] = f[i-2][0] + f[i-1][1] + f[i-2][2]
// f[i][1] = f[i-1][2]
// f[i][2] = f[i][0] + f[i-1][1]
// 边界条件
//  f[0][0] = f[1][1] = f[0][2] = 1
#include <iostream>
#include <cstring>
using namespace std;
int table[31][3];

void init() {
    memset(table, 0, sizeof(table));
    table[0][0] = table[1][1] = table[0][2] = 1;
    for (int i = 2; i <= 30; i++) {
        table[i][0] = table[i-2][0] + table[i-1][1] + table[i-2][2];
        table[i][1] = table[i-1][2];
        table[i][2] = table[i][0] + table[i-1][1];
    }
}
int main() {
    int n;
    init();
    while ((cin >> n) && n != -1) {
        cout << table[n][0] << endl;
    }
}