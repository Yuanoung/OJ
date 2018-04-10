//
// Created by yuanoung on 4/10/18.
//
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    bool data[1000];
    memset(data, false, sizeof(data[1000]));
    data[153] = data[370] = data[371] = data[407] = true;
    int m, n, flag;
    while (cin >> m >> n) {
        flag = 0;
        for (int i = m; i <= n; i++) {
            if (data[i]) {
                if (flag)
                    cout << " " << i;
                else {
                    cout << i;
                    flag = 1;
                }


            }
        }
        if (!flag)
            cout << "no";
        cout << endl;
    }

    return 0;
}
