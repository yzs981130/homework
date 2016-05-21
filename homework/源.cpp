#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <cstring>
using namespace std;
#define MAX 210
class num
{
public:
    string s;
    string integer;
    string fraction;
    int len_int;
    int len_fraction;
    num(string r) 
    { 
        s = r;
        len_int = r.find('.');       
        len_fraction = r.length() - r.find('.') - 1;
        if (len_int == string::npos)
        {
            len_int = s.length();
            len_fraction = 0;
            integer = s;
            fraction = "0";
        }
        else
        {
            integer = r.substr(0, len_int);
            fraction = r.substr(len_int + 1, r.length());
        }
    }
    num(const num &r)
    {
        s = r.s;
        len_int = r.len_int;
        len_fraction = r.len_fraction;
        integer = r.integer;
        fraction = r.fraction;
    }
    num(const string a, const string b)
    {
        len_int = a.length();
        len_fraction = b.length();
        integer = a;
        fraction = b;
        stringstream ss;
        ss << a << '.' << b;
        ss >> s;
    }
};
bool check_all_zero(string s)
{
    if (s == " ")
        return true;
    for (int i = 0; i < s.length(); i++)
        if (s[i] != '0')
            return false;
    return true;
}
void print_num(const num &r)
{
    int pos = r.fraction.find_last_not_of('0');
    string tmp = r.fraction.substr(0, pos + 1);

    if (check_all_zero(r.integer) && check_all_zero(r.fraction))
        cout << 0 << endl;
    else if (check_all_zero(r.integer) && !check_all_zero(r.fraction))
        cout << '.' << tmp << endl;
    else
    {
        bool flag = false;
        for (int i = 0; i < r.integer.length(); i++)
            if (r.integer[i] != '0' || flag)
            {
                cout << r.integer[i];
                flag = true;
            }
        if (tmp == "")
            cout << tmp << endl;
        else
            cout << '.' << tmp << endl;
    }
}
num multiply(const num &c, const num &r)
{
    int o[MAX], p[MAX], tmp_ans[MAX];
    memset(tmp_ans, 0, sizeof(tmp_ans));
    string tmp = r.integer + r.fraction;
    for (int i = 0; i < r.fraction.length(); i++)
        p[i] = r.fraction[r.fraction.length() - i - 1] - '0';
    for (int i = r.fraction.length(); i < r.s.length() - 1; i++)
        p[i] = r.integer[r.integer.length() - i - 1 + r.fraction.length()] - '0';
    string tmp1 = c.integer + c.fraction;
    for (int i = 0; i < c.fraction.length(); i++)
        o[i] = c.fraction[c.fraction.length() - i - 1] - '0';
    for (int i = c.fraction.length(); i < c.s.length() - 1; i++)
        o[i] = c.integer[c.integer.length() - i - 1 + c.fraction.length()] - '0';
    for (int i = 0; i < tmp.length(); i++)
        for (int j = 0; j < tmp1.length(); j++)
            tmp_ans[i + j] += p[i] * o[j];
    for(int i = 0; i < MAX; i++)
        if (tmp_ans[i] >= 10)
        {
            tmp_ans[i + 1] += tmp_ans[i] / 10;
            tmp_ans[i] = tmp_ans[i] % 10;
        }
    int pos_end = MAX - 1;
    while (tmp_ans[pos_end] == 0)pos_end--;
    string tmp_ans_fra, tmp_ans_int;
    for (int i = 0; i < c.len_fraction + r.len_fraction; i++)
        tmp_ans_fra += (tmp_ans[c.len_fraction + r.len_fraction - i - 1] + '0');
    for (int i = pos_end; i >= c.len_fraction + r.len_fraction; i--)
        tmp_ans_int += (tmp_ans[i] + '0');
    num t(tmp_ans_int, tmp_ans_fra);
    return t;
}
int main()
{
    string r;
    int n;
    while (cin >> r >> n)
    {
        num R(r), ans(r);
        if (n > 1)
        {
            for (int i = 0; i < n - 1; i++)
                ans = multiply(ans, R);
            print_num(ans);
        }
        else if (n == 0)
            cout << 1 << endl;
        else if (n == 1)
            print_num(ans);
    }
    system("pause");
    return 0;
}