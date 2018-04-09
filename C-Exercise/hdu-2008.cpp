//
// Created by Zheng Yuanoung on 2018/4/9.
//
#include <iostream>

using namespace std;

int main() {
    int zeroCnt, posCnt, nagCnt, n;
    double aNum;
    while (cin >> n && n) {
        zeroCnt = posCnt = nagCnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> aNum;
            if (aNum > 0) posCnt++;
            else if (aNum < 0) nagCnt++;
            else zeroCnt++;
        }

        cout << nagCnt << " " << zeroCnt << " " << posCnt << endl;
    }

    return 0;
}