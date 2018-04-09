//
// Created by yuanoung on 4/9/18.
//
/*
 * factor的求解：
 *      在n人中，选择n-m人的组合
 */
# include <iostream>

using namespace std;

int main() {
    long long data[21] = {0, 0, 1};
    int n, m, cnt;
    for (int j = 3; j < 21; j++)
        data[j] = (j - 1) * (data[j - 1] + data[j - 2]);

    cin >> cnt;
    while (cnt--) {
        cin >> n >> m;
        long long sum1 = 1, sum2 = 1;
        for (int i = n; i > n - m; i--)
            sum1 *= i;
        for (int i = 2; i <= m; i++)
            sum2 *= i;
        cout << sum1 / sum2 * data[m] << endl;
    }
    return 0;
}