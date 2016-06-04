#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define MAX 60
double dp[MAX][MAX];
double dis[MAX][MAX];
struct point
{
    double x;
    double y;
}p[MAX];
float cal_dis(int a, int b)
{
    return sqrt((p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y));
}
int main()
{    
    int n;
    while (cin >> n)
    {
        double ans = 999999;
        memset(dis, 0, sizeof(dis));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            cin >> p[i].x >> p[i].y;
        for(int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                dis[i][j] = dis[j][i] = cal_dis(i, j);
                dp[i][j] = dp[j][i] = 999999;
            }
        dp[2][1] = dis[2][1];

        for(int i = 1; i < n; i++)
            for (int j = 1; j < i; j++)
            {
                if (dp[i][j] + dis[j][i + 1] < dp[i + 1][i])
                    dp[i + 1][i] = dp[i][j] + dis[j][i + 1];
                if (dp[i][j] + dis[i][i + 1] < dp[i + 1][j])
                    dp[i + 1][j] = dp[i][j] + dis[i][i + 1];
            }
        for (int i = 1; i < n; i++)
            ans = min(ans, dp[n][i] + dis[i][n]);
        cout << fixed << setprecision(2) << ans << endl;
    }
    system("pause");
    return 0;
}