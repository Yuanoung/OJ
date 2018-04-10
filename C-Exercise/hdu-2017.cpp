//
// Created by yuanoung on 4/10/18.
//
#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char data[1000];
    int n;
    cin >> n;
    while (n--) {
        int total(0);
        memset(data, '\0', sizeof(char) * 1000);
        cin >> data;
        for (int i = 0; data[i] != '\0'; i++)
            if ('0' <= data[i] && data[i] <= '9') total++;

        cout << total << endl;
    }

    return 0;
}