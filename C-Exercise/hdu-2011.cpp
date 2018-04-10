//
// Created by yuanoung on 4/10/18.
//
#include <iostream>

using namespace std;

int main() {
    double data[1001], total;
    for (int i = 1, pos = 1; i < 1001; i++) {
        if (pos) data[i] = 1.0 / i;
        else data[i] = -1.0 / i;
        pos = !pos;
    }

    int m, n;
    cin >> m;
    while (m--) {
        cin >> n;
        total  = 0.0;
        for (int i =1; i <=n ; i++) {
            total += data[i];
        }

        printf("%.2lf\n", total);
    }

    return 0;
}
