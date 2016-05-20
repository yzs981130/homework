#include <iostream>
using namespace std;
const int MAX = 102;
int Map[MAX][MAX];
int dp[MAX][MAX];
int r, c;
int max(int x, int y, int z, int k)
{
    if (x < y)x = y;
    if (x < z)x = z;
    if (x < k)x = k;
    return x;
}
int dfs(int i, int j, int height)
{
    if (Map[i][j] == -1 || height <= Map[i][j])return 0;
    if (dp[i][j] >= 0)return dp[i][j];
    dp[i][j] = max(dfs(i + 1, j, Map[i][j]), dfs(i - 1, j, Map[i][j]), dfs(i, j + 1, Map[i][j]), dfs(i, j - 1, Map[i][j])) + 1;
    return dp[i][j];
}
int main()
{
    cin >> r >> c;
    memset(Map, -1, sizeof(Map));
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> Map[i][j];
    memset(dp, -1, sizeof(dp));
    int t_max = -1;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
        {
            int t = dfs(i, j, Map[i][j] + 1);
            if (t > t_max) t_max = t;
        }
    cout << t_max << endl;
    system("pause");
    return 0;
}