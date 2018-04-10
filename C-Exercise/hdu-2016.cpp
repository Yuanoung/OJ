//
// Created by yuanoung on 4/10/18.
//
#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
    return;
}

int main() {
    int n, data[100], minIndex;
    while ((cin >> n) and n) {
        cin >> data[0];
        minIndex = 0;
        for (int i = 1; i < n; i++) {
            cin >> data[i];
            if (data[i] < data[minIndex])   minIndex = i;
        }
        swap(data[0], data[minIndex]);
        for (int i = 0; i < n; i++) {
            if (i)  cout << " " << data[i];
            else    cout << data[i];
        }
        cout << endl;

    }
    return 0;
}
