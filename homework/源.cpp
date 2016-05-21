#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
using namespace std;
#define N 252
long long dp[N][N];
int main()
{
    int t;
    for (int i = 1; i < N; i++)
    {
        dp[0][i] = 1;
        for (int j = i / 2 + 1; j <= i; j++)
            dp[i][j] = 1;
    }
    for (int i = 2; i < N; i++)
        for (int j = i / 2; j > 0; j--)
            dp[i][j] = dp[i - 2 * j][j] + dp[i][j + 1];
    while (cin >> t && t != 0)
    {
        cout << t << ' ' << dp[t][1] << endl;
    }
    system("pause");
    return 0;
}