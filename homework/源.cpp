#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
double num[2];
stack<double> c;
multiset<double> m;
void cal_num()
{
    num[1] = c.top();
    c.pop();
    num[0] = c.top();
    c.pop();
}
void print()
{
    multiset<double>::iterator p = m.begin();
    int cnt = 0;
    for (; p != m.end(); ++p)
    {
        printf("%le ", *p);
        cnt++;
        if (cnt % 10 == 0)
            printf("\n");
    }
}
double my_stod(string s)
{
    stringstream ss;
    double n;
    ss << s;
    ss >> n;
    return n;
}
int main()
{
    int n;
    cin >> n;
    double ini;
    for (int i = 0; i < n; i++)
    {
        scanf("%le", &ini);
        m.insert(ini);
    }
    string tmp;
    while (cin >> tmp)
    {
        if (tmp == "+")
        {
            cal_num();
            c.push((num[0] + num[1]));
        }
        else if (tmp == "-")
        {
            cal_num();
            c.push((num[0] - num[1]));
        }
        else if (tmp == "*")
        {
            cal_num();
            c.push((num[0] * num[1]));
        }
        else if (tmp == "/")
        {
            cal_num();
            c.push((num[0] / num[1]));
        }
        else if (tmp == "^")
        {
            cal_num();
            c.push(pow(num[0], num[1]));
        }
        else if (tmp == "=")
        {
            printf("%le\n", c.top());
            m.erase(m.begin());
            m.insert(c.top());
            c.pop();
        }
        else
        {
            ini = my_stod(tmp);
            c.push(ini);
        }
    }
    printf("\n");
    print();
    system("pause");
    return 0;
}