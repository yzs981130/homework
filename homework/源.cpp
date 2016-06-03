#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1002
int a[MAX], dp[MAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i] = a[i];
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                if (dp[i] < dp[j] + a[i])
                    dp[i] = dp[j] + a[i];
    }
    sort(dp + 1, dp + n + 1);
    cout << dp[n] << endl;
    system("pause");
    return 0;
}