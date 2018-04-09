//
// Created by yuanoung on 4/8/18.
//

#include <iostream>
#include <stdio.h>
using namespace std;
long long data[31][2], ss = 2;

int main() {
    int cnt, n;
    data[0][0] = data[0][1] = data[1][1] = 0;
    data[1][0] = data[2][1] = 1;
    data[2][0] = 2;
    for (int i = 3; i < 21; i++) {
        ss *= i;
        data[i][0] = ss;
        data[i][1] = (i - 1) * (data[i-1][1] + data[i-2][1]);
    }
    cin >> cnt;
    while (cnt--) {
        cin >> n;
        printf("%.2lf%%\n", (100.0 * data[n][1] / data[n][0]));
    }
}