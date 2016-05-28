#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<climits>
#include<string.h>
#define MAX 4
bool m[MAX][MAX];
int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
int step;
bool flag = false;
using namespace std;
bool is_valid()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (m[i][j] != m[0][0])
                return false;
    return true;
}
void flip(int x, int y)
{
    m[x][y] = !m[x][y];
    for (int i = 0; i < 4; i++)
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (tx < 0 || tx >= MAX || ty < 0 || ty >= MAX)
            continue;
        m[tx][ty] = !m[tx][ty];
    }
}
void dfs(int x, int y, int depth)
{
    if (depth == step)
    {
        flag = is_valid();
        return;
    }
    if (flag || x >= MAX)
        return;
    flip(x, y);
    if (y + 1 < MAX)
        dfs(x, y + 1, depth + 1);
    else
        dfs(x + 1, 0, depth + 1);
    flip(x, y);
    if (y + 1 < MAX)
        dfs(x, y + 1, depth);
    else
        dfs(x + 1, 0, depth);
}
int main()
{
    char c;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            cin >> c;
            if (c == 'b')
                m[i][j] = true;
        }
    for (step = 0; step < 16; step++)
    {
        dfs(0, 0, 0);
        if (flag)
            break;
    }
    if (flag)
        cout << step << endl;
    else
        cout << "Impossible" << endl;
    system("pause");
    return 0;
}