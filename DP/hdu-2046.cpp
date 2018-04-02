//
// Created by yuanoung on 4/2/18.
//
#include <iostream>
using namespace std;
long long int data[51] = {1, 1};


int main() {
    int n;
    for (int i = 2; i < 51; i++)
        data[i] = data[i - 1] + data[i - 2];
    while ((cin >> n)) {
        cout << data[n] << endl;
    }
}