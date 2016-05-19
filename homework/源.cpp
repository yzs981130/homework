#include <memory>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory>
#include <cmath>
using namespace std;
int cal(string s1, string s2)
{
    int cnt = 0;
    for (int i = 0; i < min(s1.length(), s2.length()); i++)
    {
        if (s1[i] == s2[i])
            cnt++;
        else
            break;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    string str[10002];
    for (int i = 0; i < n; i++)
        cin >> str[i];
    string s = str[0];
    for (int i = 1; i < n; i++)
    {
        s += char(cal(str[i], str[i - 1]) + '0');
        s += str[i].substr(cal(str[i], str[i - 1]), str[i].length());
    }
    cout << s.length() << endl;
    system("pause");
    return 0;
}