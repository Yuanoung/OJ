//
// Created by yuanoung on 4/9/18.
//
#include <iostream>
using namespace std;

long long data[31] = {0, 1};

int main() {
    for (int i = 2; i < 31; i++)
        data[i] = (data[i-1] + 1) << 1;

    int n;
    while (cin >> n) {
        cout << data[n] << endl;
    }
}
