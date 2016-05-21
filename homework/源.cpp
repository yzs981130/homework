#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cstring>
using namespace std;
int dp[12882];
int w[3403];
int v[3403];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[m] << endl;
    system("pause");
    return 0;
}