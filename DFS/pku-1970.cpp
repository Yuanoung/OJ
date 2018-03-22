//
// Created by yuanoung on 18-3-22.
//
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int grid[21][21] = {0};
int direction[4][2] = {{0,  1},  // 向右
                       {1,  0},  // 向下
                       {1,  1},  // 向右下角
                       {-1, 1}}; // 向左下角

void inputData() {
    memset(grid, 0, sizeof(grid));
    for (int i = 1; i <= 19; ++i)
        for (int j = 1; j <= 19; ++j)
            scanf("%d", &grid[i][j]);  // 不用cin。对于大量的数据读取，用scanf更快
}

int main() {
    int caseCount(0), matchCount = 0;
    int row(0), col(0), directionIndex(0);
    scanf("%d", &caseCount);
    while (caseCount--) {
        inputData();
        for (row = 1; row <= 19; ++row) {
            for (col = 1; col <= 19; ++col) {
                if (grid[row][col] == 0)  // 空白处，跳过
                    continue;

                for (directionIndex = 0; directionIndex <= 3; ++directionIndex) {
                    int x = row - direction[directionIndex][0];
                    int y = col - direction[directionIndex][1];
                    if (grid[row][col] == grid[x][y])  // 表明之前已经计算过了
                        continue;

                    x = row, y = col;
                    for (matchCount = 1; matchCount <= 4; ++matchCount) {
                        x += direction[directionIndex][0];
                        y += direction[directionIndex][1];
                        if (grid[row][col] != grid[x][y])
                            break;
                    }

                    if (matchCount == 5) {  // 题目的规则，只有5连才算可以
                        x += direction[directionIndex][0];
                        y += direction[directionIndex][1];
                        if (grid[row][col] == grid[x][y])
                            continue;
                        else
                            break;
                    }

                }
                if (directionIndex <= 3)  // 说明有人赢了
                    break;
            }
            if (col <= 19)  // 说明有人赢了
                break;
        }
        if (row < 19) {  // 是否有人获胜
            cout << grid[row][col] << endl;
            cout << row << " " << col << endl;

        } else
            cout << "0" << endl;
    }
    return 0;
}
