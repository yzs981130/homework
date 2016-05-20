#include <memory>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory>
#include <cmath>
#include <queue>
#include <functional>
using namespace std;
priority_queue <string, vector<string>, greater<string> >q[1000];
void IO(int &n, int &cnt, bool &flag)
{
    string str;
    cin >> str;
    if (flag && str != "#")
    {
        cout << "DATA SET " << cnt << ":\nROOT\n";
        flag = false;
    }
    if (str[0] == 'd')
    {
        n++;
        for (int i = 0; i < n; i++)
            cout << "|     ";
        cout << str << endl;
    }

    else if (str[0] == 'f')
    {
        q[n].push(str);
    }
    else if (str == "]" || str == "*")
    {
        while (!q[n].empty())
        {
            for (int i = 0; i < n; i++)
                cout << "|     ";
            cout << q[n].top() << endl;
            q[n].pop();
        }
        n--;
    }
    if (str == "*")
    {
        cnt++;
        n = 0;
        flag = true;
        cout << endl;
    }
    if (str != "#")
        IO(n, cnt, flag);
}
int main()
{
    int i = 0, cnt = 1;
    bool flag = true;
    IO(i, cnt, flag);
    system("pause");
    return 0;
}