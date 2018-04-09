//
// Created by Zheng Yuanoung on 2018/4/9.
//
#include <iostream>

using namespace std;
char data[11] = {'E', 'E', 'E', 'E', 'E', 'E', 'D', 'C', 'B', 'A', 'A'};

int main() {
    int score;
    while (cin >> score) {
        if (score < 0 || score > 100)
            cout << "Score is error!\n";
        else
            cout << data[score / 10] << endl;
    }

    return 0;
}