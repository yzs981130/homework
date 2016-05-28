#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<climits>
#include<stdlib.h>
#include<string.h>
#define MAX 5
using namespace std;
int dir[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
int m[MAX][MAX], vis[MAX][MAX];
struct node
{
    int x;
    int y;
    int pre;
}que[1000];
int head = 0, tail = 1;
void print(int i)
{
    if (que[i].pre != -1)
    {
        print(que[i].pre);
        cout << '(' << que[i].x << ", " << que[i].y << ')' << endl;
    }
}
void bfs(int x, int y)
{
    que[head].x = x;
    que[head].y = y;
    que[head].pre = -1;
    bool flag = false;
    while (head < tail)
    {
        for (int i = 0; i < 4; i++)
        {
            int tx = que[head].x + dir[i][0];
            int ty = que[head].y + dir[i][1];
            if (tx < 0 || tx >= MAX || ty < 0 || ty >= MAX || vis[tx][ty] == 1 || m[tx][ty] == 1)
                continue;
            else
            {
                vis[x][y] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].pre = head;
                tail++;
            }
            if (tx == MAX - 1 && ty == MAX - 1)
            {
                print(head);
                flag = true;
            }
        }
        if (flag)
            break;
        head++;
    }
}
int main()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> m[i][j];
    memset(vis, 0, sizeof(vis));
    vis[0][0] = 1;
    cout << "(0, 0)" << endl;
    bfs(0, 0);
    cout << "(4, 4)" << endl;
    system("pause");
    return 0;
}