#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cstring>
using namespace std;
int a[26], b[26];
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
        a[s1[i] - 'A']++;
    for (int i = 0; i < s2.length(); i++)
        b[s2[i] - 'A']++;
    sort(a, a + 26);
    sort(b, b + 26);
    for(int i = 0; i < 26; i++)
        if (a[i] != b[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    system("pause");
    return 0;
}