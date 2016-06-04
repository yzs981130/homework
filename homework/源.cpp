#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
int cmp[26][26];
bool vis[26][26];
#define nMen 1024
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Case " << i << ':' << endl;
        memset(cmp, 0, sizeof(cmp));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                cmp[i][j] = nMen;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string tmp;
            char left_c, right_c;
            cin >> tmp;
            if (tmp[1] == '>')
            {
                left_c = tmp[2];
                right_c = tmp[0];
            }
            else
            {
                left_c = tmp[0];
                right_c = tmp[2];
            }
            cmp[left_c - 'A'][right_c - 'A'] = 0;
            cmp[right_c - 'A'][left_c - 'A'] = 1;
            vis[left_c - 'A'][right_c - 'A'] = true;
            for (int k = 0; k < 26; k++)
                for (int i = 0; i < 26; i++)
                    for (int j = 0; j < 26; j++)
                        if (cmp[i][k] == 0 && cmp[k][j] == 0 && cmp[i][j] != 0)
                            cmp[i][j] = 0;
        }
        bool flag = true;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)                
               if (cmp[i][j] == 0 && !vis[i][j])
               {
                   cout << char('A' + i) << '<' << char('A' + j) << endl;
                   vis[i][j] = true;
                   flag = false;
               }
        if (flag)
            cout << "NONE" << endl;
    }
    system("pause");
    return 0;
}