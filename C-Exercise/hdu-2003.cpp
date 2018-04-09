//
// Created by Zheng Yuanoung on 2018/4/9.
//
#include <iostream>

using namespace std;

int main() {
    double number;
    while (cin >> number) {
        if (number < 0)
            number = -number;
        printf("%.2lf\n", number);
    }

    return 0;
}
