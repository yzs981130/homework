#include <iostream>
#include <cstdio>
#include <memory.h>
#include <cstring>
#define N 2050
using namespace std;
int n;
char s[N / 2][N];
void cal(int x, int y, int d)
{
    int offset = 1 << (d - 1);
    if (d == 1)
    {
        s[x][y] = s[x + 1][y - 1] = '/';
        s[x][y + 1] = s[x + 1][y + 2] = '\\';
        s[x + 1][y] = s[x + 1][y + 1] = '_';
        return;
    }
    cal(x, y, d - 1);
    cal(x + offset, y - offset, d - 1);
    cal(x + offset, y + offset, d - 1);
}
int main()
{
    while (cin >> n && n != 0)
    {
        memset(s, ' ', sizeof(s));
        cal(1, (1 << n), n);
        int k = (1 << n) + 1;
        for (int i = 1; i <= (1 << n); i++, k++)
        {
            for (int j = 1; j <= k; j++)
                putchar(s[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}