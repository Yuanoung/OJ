//
// Created by yuanoung on 4/2/18.
//
#include <iostream>
using namespace std;
long long int data[51];

void init() {
    data[0] = 0;
    data[1] = 0;
    data[2] = 1;
    data[3] = 2;
    for (int i = 4; i < 51; i++) {
        data[i] = data[i-1] + data[i-2];  //状态方程
    }
}

int main() {
    int n, a, b;
    init();
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << data[b - a + 1] << endl;
    }
}
