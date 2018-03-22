//
// Created by yuanoung on 18-3-22.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 19;
const int stepX[] = {-1, 0, 1, 1};//四个方向
const int stepY[] = {1, 1, 1, 0};
int visit[MAXN + 3][MAXN + 3][4];//visit[i][j][k]表示位于[i][j]位置的棋子的k方向是否已被搜索过
int map[MAXN + 2][MAXN + 2];//存图
int cnt;

void DFS(int x, int y, int id, int dir) {//x,y为坐标，id为1或者2,dire代表方位，即确定方位的进行搜索
    visit[x][y][dir] = 1;
    int nex = x + stepX[dir], ney = y + stepY[dir];
    if (map[nex][ney] == id) {
        ++cnt;//统计连子数
        DFS(nex, ney, id, dir);
    }
}

int main() {
    int t, r, c, dir;
    scanf("%d", &t);
    while (t--) {
        memset(visit, 0, sizeof(visit));
        memset(map, 0, sizeof(map));
        cnt = 0;
        for (r = 1; r <= 19; r++) {
            for (c = 1; c <= 19; c++) {
                scanf("%d", &map[r][c]);
            }
        }
        int leftX = -1, leftY = -1;//五连子最左边棋子的坐标
        int win = 0;//获胜的标志
        for (r = 1; r <= 19; r++) {
            for (c = 1; c <= 19; c++) {
                if (!map[r][c]) continue;  // 如果为空，跳过
                for (dir = 0; dir < 4; dir++) {  // dir
                    if (!visit[r][c][dir]) {
                        cnt = 1;
                        DFS(r, c, map[r][c], dir);
                        if (cnt == 5 && map[r - stepX[dir]][c - stepY[dir]] != map[r][c]) {
                            //判断是否为五连子且考虑反方向是否会造成六连子
                            //为什么只考虑相反的方向呢？因为如果正方向还是相同的颜色，显然cnt不为５
                            win = map[r][c], leftX = r, leftY = c;
                        }
                    }
                    if (win) break;
                }
                if (dir < 4) break;
            }
            if (c <= 19) break;
        }
        printf("%d\n", win);
        if (win) printf("%d %d\n", leftX, leftY);
    }
    return 0;
}
