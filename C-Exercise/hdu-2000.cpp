//
// Created by yuanoung on 4/9/18.
//
#include <iostream>

using namespace std;

int main() {
    char c1, c2, c3;
    while (cin >> c1 >> c2 >> c3) {
        if (c2 < c1) {
            if (c3 >= c1)
                cout << c2 << " " << c1 << " " << c3 << endl;
            else if (c3 < c2)
                cout << c3 << " " << c2 << " " << c1 << endl;
            else
                cout << c2 << " " << c3 << " " << c1 << endl;
        } else {
            if (c3 < c1)
                cout << c3 << " " << c1 << " " << c2 << endl;
            else if (c3 < c2)
                cout << c1 << " " << c3 << " " << c2 << endl;
            else
                cout << c1 << " " << c2 << " " << c3 << endl;
        }
    }

    return 0;
}
