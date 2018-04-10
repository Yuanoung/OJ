//
// Created by yuanoung on 4/10/18.
//
#include <iostream>
using namespace std;

int main() {
    int n, m, data[101] = {2};
    for (int i = 1; i < 101; i++)
        data[i] = data[i - 1] + 2;
    while (cin >> n >> m) {
        int cnt = n / m + 1;

    }
    return 0;
}
