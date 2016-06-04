#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 202
char m[MAX][MAX];
bool vis[MAX][MAX];
int step[MAX][MAX];
int r, c;
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
struct point
{
    int x;
    int y;
    point(int _x, int _y):x(_x), y(_y){}
};
bool is_valid(int x, int y)
{
    if (vis[x][y] == true || x >= r || x < 0 || y >= c || y < 0 || m[x][y] == '#')
        return false;
    return true;
}
int bfs(int b_x, int b_y, int e_x, int e_y)
{
    point p(b_x, b_y);
    queue<point> q;
    q.push(p);
    vis[b_x][b_y] = true;
    while (!q.empty())
    {
        point c = q.front();
        q.pop();
        if (c.x == e_x && c.y == e_y)
            return step[e_x][e_y];
        for (int i = 0; i < 4; i++)
        {
            if(!is_valid(c.x + dir[i][0], c.y + dir[i][1]))
                continue;
            point d(c.x + dir[i][0], c.y + dir[i][1]);
            vis[c.x + dir[i][0]][c.y + dir[i][1]] = true;
            q.push(d);
            step[c.x + dir[i][0]][c.y + dir[i][1]] = step[c.x][c.y] + 1;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(m, 0, sizeof(m));
        memset(step, 0, sizeof(step));
        memset(vis, 0, sizeof(vis));
        cin >> r >> c;
        int b_x, b_y, e_x, e_y;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> m[i][j];
                if (m[i][j] == 'S')
                {
                    b_x = i;
                    b_y = j;
                }
                if (m[i][j] == 'E')
                {
                    e_x = i;
                    e_y = j;
                }
            }
        int t = bfs(b_x, b_y, e_x, e_y);
        if (t == -1)
            cout << "oop!" << endl;
        else
            cout << t << endl;
    }
    system("pause");
    return 0;
}