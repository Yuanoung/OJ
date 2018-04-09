//
// Created by Zheng Yuanoung on 2018/4/9.
//
#include <iostream>

using namespace std;

int main() {
    long long  evenSum, oddSum;
    int numL, numR;
    while (cin >> numL >> numR) {
        evenSum = oddSum = 0;
        if (numL > numR) {
            int temp = numL;
            numL = numR;
            numR = temp;
        }
        for (int i = numL; i <= numR; i++) {
            if (i % 2 == 0)
                evenSum += i * i;
            else
                oddSum += i * i * i;
        }

        cout << evenSum << " " << oddSum << endl;
    }

    return 0;
}
