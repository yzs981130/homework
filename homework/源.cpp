#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct Pos
{
    int x;
    int y;
    int step;
    Pos(int _x = 0, int _y = 0):x(_x), y(_y){}
};
int n, dir[8][2] = {{1, 2},{2, 1},{2, -1},{1, -2},{-1, -2},{-2, -1},{-2, 1},{-1, 2}};
bool vis[310][310];
bool valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < n)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        Pos st, en;
        memset(vis, 0, sizeof(vis));
        cin >> st.x >> st.y >> en.x >> en.y;
        vis[st.x][st.y] = true;
        st.step = 0;
        queue<Pos> q;
        q.push(st);
        while (!q.empty())
        {
            Pos tmp = q.front();
            q.pop();
            if (tmp.x == en.x && tmp.y == en.y)
            {
                cout << tmp.step << endl;
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                int tx = tmp.x + dir[i][0], ty = tmp.y + dir[i][1];
                if (!vis[tx][ty] && valid(tx, ty))
                {
                    Pos m(tx, ty);
                    m.step = tmp.step + 1;
                    q.push(m);
                    vis[tx][ty] = true;
                }
            }
        }
    }
    system("pause");
    return 0;
}