//
// Created by yuanoung on 4/2/18.
//
#include <iostream>
using namespace std;

long long int data[70] = {0, 3, 6, 6};
void init() {
    for (int i = 4; i < 70; i++) {
        data[i] = data[i - 1] + data[i - 2] * 2;
    }
}
int main() {
    int n;
    init();
    while ((cin >> n)) {
        cout << data[n] << endl;
    }
}