//
// Created by yuanoung on 3/23/18.
//
#include <iostream>
#include <cstring>
using namespace std;

int tree[11000], node1, node2;
int inputNumber(0), parentNode, newNode;

bool dfs(int node) {
    for (int i = 1; i < inputNumber + 1; i++) {  // inputNumber + 1, 16除去最后一行都是输入，也就是１５,但是里面最大的数字是１６
        if (tree[i] == node)    {  // i是子字节
            if (i == node2)     return true;
            if (dfs(i)) return true;
        }
    }
    return false;
}

int main() {
    int Case(0);
    cin >> Case;
    while (Case--) {
        cin >> inputNumber;
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i < inputNumber; i++) {
            cin >> parentNode >> newNode;
            tree[newNode] = parentNode;
        }
        cin >> node1 >> node2;
        int node = node1;
        while (true) {
            if (dfs(node)) {
                cout << node << endl;
                break;
            }
            node = tree[node];
        }
    }
}
