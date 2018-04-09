//
// Created by yuanoung on 4/9/18.
//
#include <iostream>

using namespace std;

int main() {
    char c[3];
    while (cin >> c) {
        for (int i = 0; i < 2; i++)
            for (int j = 2; j > i; j--) {
                if (c[j] < c[j - 1]) {
                    char temp = c[j];
                    c[j] = c[j - 1];
                    c[j - 1] = temp;
                }
            }
        cout << c[0] << " " << c[1] << " " << c[2] << endl;
    }

    return 0;
}
