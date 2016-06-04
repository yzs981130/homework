#include <iostream>
using namespace std;
int n, k;
int ans;
char m[9][9];
bool vis[9][9];
bool canPut(int x, int y)
{
    for (int i = 0; i < n; ++i)
    {
        if (m[x][i] == '#' && vis[x][i]) 
            return false;
        if (m[i][y] == '#' && vis[i][y]) 
            return false;
    }
    return true;
}
void dfs(int row, int cnt_left)
{
    if (cnt_left == 0)
    {
        ans++;
        return;
    }
    for(int i = row; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == '#' && !vis[i][j] && canPut(i, j))
            {
                vis[i][j] = true;
                dfs(i + 1, cnt_left - 1);
                vis[i][j] = false;
            }
        }
}
int main()
{
    while (cin >> n >> k && (n != -1))
    {
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];
        dfs(0, k);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}