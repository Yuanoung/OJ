//1. 设f(n)为整数n时，满足涂法的全部个数．
//2. 转化到子问题上，找出递归式或者状态方程：
//　　f(n) = f(n-2)*6 + 2*(f(n-1)-f(n-2)*2)=2(f(n-1) + f(n-2))
//    f(n-2)*2*3：n-1可以选择E F，n位可以选择E,O,F．
//　　f(n-1)-f(n-2)*2是为了得到n-1位为O的情况的个数，所以2*(f(n-1)-f(n-2)*2)为n-1位为O，　n位为E, F情况的个数
//3.确定基本条件：
//　f(0)=1,f(1)=3,f(2)=8．
//
// Created by yuanoung on 4/2/18.
//
#include <iostream>
using namespace std;

long long int data[41] = {1, 3};

int main() {
    int n;
    for (int i = 2; i < 41; i++)
        data[i] = (data[i-1] + data[i-2]) << 1;
    while ((cin >> n)) {
        cout << data[n] << endl;
    }
}