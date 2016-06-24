#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int t, m, v[101], c[101], dp[1010];
int main()
{
    cin >> t >> m;
    for (int i = 0; i < m; i++)
        cin >> c[i] >> v[i];
    for (int i = 0; i < m; i++)
        for (int j = t; j >= c[i]; j--)
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
    cout << dp[t];
    system("pause");
    return 0;
}