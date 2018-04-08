//
// Created by yuanoung on 4/8/18.
//

#include <iostream>
using namespace std;
long long data[21], ss = 1;

int main() {
    int cnt, n;
    for (int i = 1; i < 21; i++) {
        ss *= i;
    }
    cin >> cnt;
    while (cnt--) {
        cin >> n;
    }
}