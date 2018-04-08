//
// Created by yuanoung on 4/2/18.
//
#include <iostream>
using namespace std;
long long data[10001] = {1, 2};

int main() {
    for (int i = 2; i < 10001; i++)
        data[i] = data[i-1] + 4 * (i - 1) + 1;
    int cnt, n;
    cin >> cnt;
    while (cnt--) {
        cin >> n;
        cout << data[n] << endl;
    }
}
