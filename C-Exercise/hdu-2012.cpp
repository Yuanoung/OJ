//
// Created by yuanoung on 4/10/18.
//
#include <iostream>
#include <cstring>

using namespace std;
bool data[2600] = {true};

int main() {
    memset(data, true, sizeof(bool) * 2600);
    data[0] = data[1] = false;
    for (int i = 2; i < 2600; i++) {
        if (data[i]) {
            for (int j = i; i + j < 2600;) {
                data[i + j] = false;
                j += i;
            }
        }
    }
    int x, y;
    while ((cin >> x >> y) && (x || y)) {
        int flag(1);
        for (int i = x; i <= y; i++) {
            int val = i * i + i + 41;
            if (!data[val]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "OK\n";
        else
            cout << "Sorry\n";
    }

    return 0;
}
