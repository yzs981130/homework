#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<string.h>
#define MAX 10
char m[MAX][MAX];
int n, k;
int cnt;
bool vis[MAX];
using namespace std;
void dfs(int row, int num)
{
    if (num == k)
    {
        cnt++;
        return;
    }
    for(int i = row; i < n; i++)
        for(int j = 0; j < n; j++)
            if (m[i][j] == '#' && !vis[j])
            {
                vis[j] = true;
                dfs(i + 1, num + 1);
                vis[j] = false;
            }
}
int main()
{
    while (cin >> n >> k && (n != -1))
    {
        cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(m, 0, sizeof(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> m[i][j];
        dfs(0, 0);
        cout << cnt << endl;
    }
    system("pause");
    return 0;
}