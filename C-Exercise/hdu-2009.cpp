//
// Created by yuanoung on 4/10/18.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        double total = n, prev = n;
        while (--m) {
            prev = sqrt(prev);
            total += prev;
        }

        printf("%.2lf\n", total);
    }

    return 0;
}