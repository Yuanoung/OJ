//
// Created by yuanoung on 4/10/18.
//
#include <iostream>

using namespace std;

int main() {
    int n, score, total, minS, maxS;
    while (cin >> n) {
        cin >> score;
        total = minS = maxS = score;
        for (int i = 1; i < n; i++) {
            cin >> score;
            if (score < minS) minS = score;
            if (score > maxS) maxS = score;
            total += score;
        }
        printf("%.2lf\n", 1.0 * (total - maxS - minS) / (n - 2));
    }

    return 0;
}