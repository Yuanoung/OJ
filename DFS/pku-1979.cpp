//
// Created by yuanoung on 18-3-22.
//
/* Red and Black ★☆☆☆☆
** BFS-FloodFilld算法
*/
#include <iostream>
#include <cstring>

using namespace std;

char tiles[20][20];
int result(0), row(0), col(0);


bool jugle(int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= col || tiles[x][y] == '#')
        return true;
    else
        return false;
}

void dfs(int x, int y) {
    if (jugle(x, y)) return;

    result += 1;
    tiles[x][y] = '#';
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
    return;
}

int main() {
    while (cin >> col >> row && col) {
        result = 0;
        memset(tiles, '#', sizeof(tiles));
        int sx(0), sy(0);
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++) {
                cin >> tiles[r][c];
                if (tiles[r][c] == '@') {
                    sx = r;
                    sy = c;
                }
            }
        dfs(sx, sy);
        cout << result << endl;
    }

    return 0;
}
