//
// Created by Zheng Yuanoung on 2018/4/9.
//
#include <iostream>
using namespace std;

#define PI 3.1415927

int main () {
    double radius;
    while (cin >> radius) {
        printf("%.3lf\n", 4.0 / 3 * PI * radius * radius * radius);
    }

    return 0;
}