//
// Created by Zheng Yuanoung on 2018/4/9.
//
#include <iostream>

using namespace std;

int main() {
    long long total;
    int n, aNum;
    while (cin >> n) {
        total = 1;
        for (int i = 0; i < n; i++) {
            cin >> aNum;
            if (aNum % 2 != 0) {
                total *= aNum;
            }
        }
        cout << total << endl;
    }

    return 0;
}
